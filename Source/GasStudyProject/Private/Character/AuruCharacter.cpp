// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuruCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AAuruCharacter::AAuruCharacter()
{
	//RootComponent=CreateDefaultSubobject<USceneComponent>("RootComp");

	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent=CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComponent->SetupAttachment(SpringArmComponent);

	//调整角色移动旋转方式
	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane=true;
	GetCharacterMovement()->bSnapToPlaneAtStart=true;

	bUseControllerRotationPitch=false;
	bUseControllerRotationRoll=false;
	bUseControllerRotationYaw=false;



	
}
