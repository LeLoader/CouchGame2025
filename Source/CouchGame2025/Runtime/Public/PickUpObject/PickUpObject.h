// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CouchGame2025/Runtime/Public/Interface/Interactable.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "PickUpObject.generated.h"

class ACouchGame2025Character;

UCLASS()
class COUCHGAME2025_API APickUpObject : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickUpObject();

	bool Interact(ACouchGame2025Character* A) override;

	UFUNCTION(BlueprintCallable)
	virtual void StartPickUp(ACouchGame2025Character* Player);

	UFUNCTION(BlueprintCallable)
	void StopPickUp(ACouchGame2025Character* Player);
	
	UPROPERTY()
	ACouchGame2025Character* Interactor;


	int GetPriority() override;


	bool CanBeInteractWithSomethingInHand() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LaunchForce;

	UFUNCTION(BlueprintImplementableEvent)
	void OnLaunched();


#pragma region MultiPlayerHolding

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NeedsTwoPlayersToBePickedUp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsAPlayerHolding;

	UPROPERTY()
	bool bIsPickedUp;

	UPROPERTY()
	bool bCanBePickedUp;

private:

	UPROPERTY()
	TArray<ACouchGame2025Character*> PlayersHolding;

	UFUNCTION()
	void ReleaseObjectFromOnePlayer(ACouchGame2025Character* PlayerReleasing);

	UPROPERTY()
	bool bIsGrabbedByBoth;

	UPROPERTY()
	FVector2D PlayersAverageInput;

	UFUNCTION()
	void EnableCollision();
#pragma endregion
};
