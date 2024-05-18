// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuruCharacterBase.h"
#include "..\Interaction\TargetInterface.h"
#include "AuruEnemy.generated.h"

/**
 * 
 */
UCLASS()
class GASSTUDYPROJECT_API AAuruEnemy : public AAuruCharacterBase,public ITargetInterface
{
	GENERATED_BODY()
public:
	AAuruEnemy();
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;

};
