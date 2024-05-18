// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuruCharacterBase.h"

AAuruCharacterBase::AAuruCharacterBase()
{

	PrimaryActorTick.bCanEverTick = false;


	//创建玩家武器组件
	Weapon=CreateDefaultSubobject<USkeletalMeshComponent>("WeaponComp");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);

}

void AAuruCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



