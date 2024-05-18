// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/TargetInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates=true;
	
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//查看输入映射表是否存在不存在则崩溃
	check(AuraContext);
	if(UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		EnhancedInputLocalPlayerSubsystem->AddMappingContext(AuraContext,0);
	}

	bShowMouseCursor=true;
	DefaultMouseCursor=EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{

	const FVector2D InputAxisVector=InputActionValue.Get<FVector2D>();
	const FRotator ControllerRotator=GetControlRotation();
	const FRotator YawRotator=FRotator(0,ControllerRotator.Yaw,0);
	const FVector ForwardVector=FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
	const FVector RightVector=FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
	if(APawn* ControlledPawn=GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardVector,InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightVector,InputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);

	if(!CursorHit.bBlockingHit) return;
	LastActor=ThisActor;
	ThisActor=Cast<ITargetInterface>(CursorHit.GetActor());

	/*
	 *	鼠标的碰撞检测，有以下几种情况：
	 *	1.LastActor是空，ThisActor是空
	 *		-什么也不做
	 *	2.LastActor是空，ThisActor是有效的
	 *		-HighlightThisActor
	 *	3.LastActor是有效的，ThisActor是空
	 *		-Unhighlight LastActor
	 *	4.LastActor是有效的且和ThisActor不相同
	 *		-Unhighlight LastActor,Highlight ThisActor
	 *  5.LastActor是有效的且和ThisActor相同
	 *		-什么也不做
	 */

	if(LastActor)//LastActor有效
	{
		if(ThisActor)
		{
			if(ThisActor!=LastActor)
			{
				//case 4
				LastActor->UnhighlightActor();
				ThisActor->HighlightActor();
			//	UE_LOG(LogTemp, Log, TEXT("4"));
			}
		}
		else
		{
			//case 3
			LastActor->UnhighlightActor();
		//	UE_LOG(LogTemp, Log, TEXT("3"));
		}
	}
	else
	{
		if(ThisActor)
		{
			//case 2
			ThisActor->HighlightActor();
		//	UE_LOG(LogTemp, Log, TEXT("2"));
		}
		else
		{
		//	UE_LOG(LogTemp, Log, TEXT("1"));
		}
	}

	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent=CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AAuraPlayerController::Move);
	
}
