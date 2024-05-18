// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuruCharacterBase.h"
#include "AuruCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class GASSTUDYPROJECT_API AAuruCharacter : public AAuruCharacterBase
{
	GENERATED_BODY()
public:
	AAuruCharacter();
	
protected:

	
private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;
	
};
