// Fill out your copyright notice in the Description page of Project Settings.


#include "CouchGame2025/Runtime/Public/Component/PlanetaryMovementComponent.h"
#include <Logging/StructuredLog.h>

UPlanetaryMovementComponent::UPlanetaryMovementComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UPlanetaryMovementComponent::BeginPlay()
{
    Super::BeginPlay();
    CachedOwnerPawn = Cast<APawn>(GetOwner());
}

void UPlanetaryMovementComponent::UpdateGravityDirection(const FVector& NewGravityDirection)
{
	SetGravityDirection(NewGravityDirection);
}

void UPlanetaryMovementComponent::InvertGravity()
{
    UseExternalGravityDirection = false;
}

bool UPlanetaryMovementComponent::DoJump(bool bReplayingMoves)
{
    if (IsMovingOnGround() && !UseExternalGravityDirection)
    {
        UseExternalGravityDirection = true;
        OnPlanetaryJumped.Broadcast();
    }

    return Super::DoJump(bReplayingMoves);
}


void UPlanetaryMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!CachedOwnerPawn) return;

    FVector CharacterPosition = CachedOwnerPawn->GetActorLocation();
    FVector GravityDir = (PlanetCenter - CharacterPosition).GetSafeNormal();

    if (!UseExternalGravityDirection)
    {
        GravityDir *= -1;
    }
    DrawDebugDirectionalArrow(GetWorld(), CharacterPosition, CharacterPosition + GravityDir * 200, 32, FColor::Red);

    UpdateGravityDirection(GravityDir);
}