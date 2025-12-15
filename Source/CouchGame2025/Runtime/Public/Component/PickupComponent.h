// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Global/CouchGame2025Character.h"
#include "Interface/Interactable.h"
#include "PickUpObject/PickUpObject.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Delegates/Delegate.h"

#include "CollisionQueryParams.h"
#include "PickupComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNewInteractionTargetSignature, AActor*, NewInteractionTarget, AActor*, OldInteractionTarget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUpSignature, APickUpObject*, PickedUpObject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnThrowSignature, APickUpObject*, PickedUpObject);

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

	UPROPERTY(BlueprintAssignable)
	FOnPickUpSignature OnPickUp;

	UPROPERTY(BlueprintAssignable)
	FOnThrowSignature OnThrow;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACouchGame2025Character* PickedUpPlayer;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APickUpObject* PickedUpObject;
private:
	UPROPERTY()
	ACouchGame2025Character* Player; // Owner Player
	
	// UPROPERTY()
	FCollisionQueryParams Params;
	

};

