#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "TransferPoint.generated.h"

UCLASS()
class COUCHGAME2025_API ATransferPoint : public AActor
{
    GENERATED_BODY()

public:
    ATransferPoint();

    UPROPERTY(EditAnywhere)
    AActor* Bp_Planet;

    UPROPERTY(EditAnywhere)
    float MoveDuration = 2.0f;

protected:
    virtual void BeginPlay() override;

    UPROPERTY()
    UCapsuleComponent* TransferPointCapsule;

    UPROPERTY(VisibleAnywhere)
    USplineComponent* SplineComponent;

public:
    virtual void Tick(float DeltaTime) override;

    void StartTransfer(AActor* Initiator);

private:
    UPROPERTY(VisibleAnywhere)
    USphereComponent* InternalPlanet = nullptr;
};