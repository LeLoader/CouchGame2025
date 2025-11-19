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

    TSet<UActorComponent*> AllComponents = GetOwner()->GetComponents();
    for (UActorComponent* Component : AllComponents) {
        if (UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(Component)) {
            StaticMesh->SetEnableGravity(false);
        }
    }
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

    UPrimitiveComponent* PrimitiveComp = Cast<UPrimitiveComponent>(Owner->GetRootComponent());
    if (!(PrimitiveComp->GetCollisionEnabled() & (ECollisionEnabled::PhysicsOnly | ECollisionEnabled::QueryAndPhysics))) return;
    if (!PrimitiveComp || !PrimitiveComp->IsSimulatingPhysics()) return;

    FVector ObjectPosition = Owner->GetActorLocation();
    FVector GravityDir = (PlanetCenter - ObjectPosition).GetSafeNormal();

    PrimitiveComp->AddForce(GravityDir * GravityForce, NAME_None, true);
}