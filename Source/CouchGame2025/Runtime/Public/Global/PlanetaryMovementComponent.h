// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlanetaryMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class COUCHGAME2025_API UPlanetaryMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void UpdateGravityDirection(const FVector& NewGravityDirection);

	UFUNCTION(BlueprintCallable)
		void InvertGravity();
};