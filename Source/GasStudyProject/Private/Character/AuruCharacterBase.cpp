// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuruCharacterBase.h"

// Sets default values
AAuruCharacterBase::AAuruCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAuruCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAuruCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAuruCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

