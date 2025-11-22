// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "CouchGame2025/Runtime/Public/Interface/Interactable.h"
#include "CouchGame2025/Runtime/Public/PickUpObject/PickUpObject.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Delegates/Delegate.h"

#include "PickupComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNewInteractionTargetSignature, AActor*, NewInteractionTarget, AActor*, OldInteractionTarget);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COUCHGAME2025_API UPickupComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPickupComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void TraceToFindNearestInteractable();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AActor> CurrentInteractionTarget;

	UPROPERTY(BlueprintAssignable)
	FOnNewInteractionTargetSignature OnNewInteractionTarget;

	UFUNCTION(BlueprintCallable)
	void TryPickUp();

	UPROPERTY(EditDefaultsOnly, meta = (Units = "cm"))
	float TraceLength = 250;

	UPROPERTY(EditDefaultsOnly, meta = (Units = "cm"))
	float TraceWidth = 100;

	// Use
	UFUNCTION()
	void StartUse();
	UFUNCTION()
	void Use();
	UFUNCTION()
	void StopUse();



	UFUNCTION()
	void HandleInputCompleted(ACouchGame2025Character* Player);

	UFUNCTION()
	void StopPickUp(ACouchGame2025Character* Player);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPhysicsHandleComponent* PhysicsHandle;

	bool IsGrabbingObject = false;

	bool bCanBeReleased = false;
private:
	UPROPERTY()
	ACouchGame2025Character* Player;

	UPROPERTY()
	APickUpObject* PickedUpObject;

};

