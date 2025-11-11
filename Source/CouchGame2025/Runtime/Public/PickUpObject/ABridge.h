#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "ABridge.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class COUCHGAME2025_API AABridge : public AActor
{
    GENERATED_BODY()

public:
    AABridge();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    void ToggleBridge();
    void UpdateBridgeState();

    void UpdateBridgeTransform();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Bridge")
    USceneComponent* Root;

    UPROPERTY(EditAnywhere, Category = "Bridge")
    USceneComponent* StartPoint;

    UPROPERTY(EditAnywhere, Category = "Bridge")
    USceneComponent* EndPoint;

    UPROPERTY(EditAnywhere, Category = "Bridge")
    UStaticMeshComponent* BridgeMesh;

    UPROPERTY(EditAnywhere, Category = "Bridge")
    float InteractionDistance = 300.f;

    UPROPERTY(VisibleAnywhere, Category = "Bridge")
    bool bIsDeployed = false;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputMappingContext* InputMappingContext;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* ToggleBridgeAction;

    float OriginalMeshLength = 1.f;
    FVector InitialMeshScale = FVector::OneVector;

    UPROPERTY(EditAnywhere, Category = "Bridge")
    float WidthHeightScale = 1.f;
};
