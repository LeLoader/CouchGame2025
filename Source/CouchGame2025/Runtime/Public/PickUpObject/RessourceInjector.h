#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Component/RessourceContainerComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "RessourceInjector.generated.h"

UCLASS(Blueprintable)
class COUCHGAME2025_API ARessourceInjector : public AActor
{
    GENERATED_BODY()

public:
    ARessourceInjector();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    URessourceContainerComponent* RessourceContainer;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Proximity")
    USphereComponent* ProximitySphere;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Proximity")
    float ProximityRadius = 200.f;

    UPROPERTY()
    ACharacter* PlayerCharacter = nullptr;

    UPROPERTY(BlueprintReadOnly)
    bool bIsFull = false;

    UFUNCTION()
    void OnProximityBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnProximityEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};