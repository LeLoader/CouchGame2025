// Fill out your copyright notice in the Description page of Project Settings.


#include "CouchGame2025/Runtime/Public/Global/PlanetaryMovementComponent.h"
#include <Logging/StructuredLog.h>


void UPlanetaryMovementComponent::UpdateGravityDirection(const FVector& NewGravityDirection)
{
	SetGravityDirection(NewGravityDirection);
}

void UPlanetaryMovementComponent::InvertGravity()
{
    FVector CurrentGravityDirection = GetGravityDirection();

    FVector InvertedGravityDirection = -CurrentGravityDirection;

    SetGravityDirection(InvertedGravityDirection);
}

bool UPlanetaryMovementComponent::DoJump(bool bReplayingMoves)
{
    if (IsMovingOnGround() && !UseExternalGravityDirection)
    {
		SetGravityDirection(-GetGravityDirection());
        UpdateGravityDirection(GetGravityDirection());
		UseExternalGravityDirection = true;
    }

    return Super::DoJump(bReplayingMoves);
}