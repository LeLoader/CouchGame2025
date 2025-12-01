#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CouchGame2025/Runtime/Public/Interface/Interactable.h"
#include "TransferPoint.generated.h"

class UBoxComponent;
class USplineComponent;
class UCameraComponent;

UCLASS()
class COUCHGAME2025_API ATransfertPoint : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    ATransfertPoint();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UBoxComponent> BoxComponent;

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    virtual bool Interact(ACouchGame2025Character* Player) override;

    UFUNCTION(BlueprintCallable)
    void SetSplineComponent(USplineComponent* InSpline);

    UFUNCTION(BlueprintCallable)
    void SetLinkedActor(AActor* InActor);

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool IsExtern;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartTransfert);
    UPROPERTY(BlueprintAssignable)
    FOnStartTransfert OnStartTransfert;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndTransfert);
    UPROPERTY(BlueprintAssignable)
    FOnEndTransfert OnEndTransfert;

private:

    bool bOnePlayerHasAlreadyInteracted;

    TObjectPtr<ACouchGame2025Character> FirstInstigator;
    TObjectPtr<ACouchGame2025Character> SecondInstigator;

    UPROPERTY()
    TObjectPtr<USplineComponent> Spline;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UCameraComponent> CameraComponent;

    UPROPERTY()
    TObjectPtr<AActor> LinkedPoint;

    UFUNCTION()
    void OnMovementAlongSplineOver();
};