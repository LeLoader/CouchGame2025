// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CouchGame2025/Runtime/Public/Interface/Interactable.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "PickUpObject.generated.h"

UCLASS()
class COUCHGAME2025_API APickUpObject : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickUpObject();

	virtual void Interact(ACouchGame2025Character* Player) override;

	UFUNCTION(BlueprintCallable)
	void StartPickUp(ACouchGame2025Character* Player);

	UFUNCTION(BlueprintCallable)
	void StopPickUp();
	
	UPROPERTY()
	ACouchGame2025Character* Interactor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> Socket;


#pragma region MultiPlayerHolding

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NeedsTwoPlayersToBePickedUp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsAPlayerHolding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UPhysicsConstraintComponent*> PhysicsConstraints;

private:

	UFUNCTION()
	UPhysicsConstraintComponent* GetClosestPhysicsConstraint();
	
#pragma endregion
};
