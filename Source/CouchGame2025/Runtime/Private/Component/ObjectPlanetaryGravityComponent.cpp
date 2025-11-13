#include "CouchGame2025/Runtime/Public\Component\ObjectPlanetaryGravityComponent.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"

UObjectPlanetaryGravityComponent::UObjectPlanetaryGravityComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UObjectPlanetaryGravityComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UObjectPlanetaryGravityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    ApplyGravity();
}

void UObjectPlanetaryGravityComponent::ApplyGravity()
{
    AActor* Owner = GetOwner();
    if (!Owner) return;

    UPrimitiveComponent* PrimitiveComp = Cast<UPrimitiveComponent>(Owner->GetComponentByClass(UPrimitiveComponent::StaticClass()));
    if (!PrimitiveComp || !PrimitiveComp->IsSimulatingPhysics() || !(PrimitiveComp->GetCollisionEnabled() != ECollisionEnabled::NoCollision)) return;

    FVector ObjectPosition = Owner->GetActorLocation();
    FVector GravityDir = (PlanetCenter - ObjectPosition).GetSafeNormal();

    PrimitiveComp->AddForce(GravityDir * GravityForce * PrimitiveComp->GetMass());
}