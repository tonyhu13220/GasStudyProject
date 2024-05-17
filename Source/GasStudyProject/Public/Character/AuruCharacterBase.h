// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuruCharacterBase.generated.h"

UCLASS()
class GASSTUDYPROJECT_API AAuruCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	AAuruCharacterBase();

protected:

	virtual void BeginPlay() override;

public:	


};
