#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Component/RessourceContainerComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Interface/Interactable.h"
#include "RessourceInjector.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);

UCLASS(Blueprintable)
class COUCHGAME2025_API ARessourceInjector : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    ARessourceInjector();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual int GetPriority() override;
    virtual bool CanBeInteractWithSomethingInHand() override;
    virtual bool Interact(ACouchGame2025Character* Character) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bIsAPlayerInteracting;

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

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    bool bIsFull = false;

    UFUNCTION()
    void OnProximityBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnProximityEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UPROPERTY(BlueprintAssignable, Category = "Interact")
    FOnInteract OnInteract;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    ACouchGame2025Character* InteractingCharacter = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    ACouchGame2025Character* PlayerTryingToInteract;
};