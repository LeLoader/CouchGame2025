#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPlanetaryGravityComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COUCHGAME2025_API UObjectPlanetaryGravityComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UObjectPlanetaryGravityComponent();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
    FVector PlanetCenter = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
    float GravityForce = 981.0f;

protected:
    void ApplyGravity();
};