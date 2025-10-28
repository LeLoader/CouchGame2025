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
	UPlanetaryMovementComponent();

	UFUNCTION(BlueprintCallable)
		void UpdateGravityDirection(const FVector& NewGravityDirection);

	UFUNCTION(BlueprintCallable)
		void InvertGravity();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseExternalGravityDirection = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
	FVector PlanetCenter = FVector::ZeroVector;

	virtual bool DoJump(bool bReplayingMoves) override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};