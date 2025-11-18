// Fill out your copyright notice in the Description page of Project Settings.


#include "CouchGame2025/Runtime/Public/PickUpObject/PickUpObject.h"

#include <string>


#include "CouchGame2025/Runtime/Public/Component/ObjectPlanetaryGravityComponent.h"
#include "CouchGame2025/Runtime/Public/Component/PickupComponent.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Logging/StructuredLog.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"


// Sets default values
APickUpObject::APickUpObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void APickUpObject::BeginPlay()
{
	Super::BeginPlay();
	IsPickedUp = false;
}

void APickUpObject::Interact(ACouchGame2025Character* Player)
{
	if (Player == nullptr) return;

	if (!NeedsTwoPlayersToBePickedUp)
	{
		StartPickUp(Player);
	}
	else
	{
		// If two players are needed to move the object around
		
		if (!IsAPlayerHolding){ // If Player is the first one to hold the object
			//Mesh->SetMobility(EComponentMobility::Type::Static);
			Player->GetCharacterMovement()->SetMovementMode(MOVE_None);
			//Player->SetLockLocation(true);
			this->AttachToComponent(
			Player->GetMesh(),
			FAttachmentTransformRules
			(EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			true),
			"Hand_Pos");
			PlayersHolding.Add(Player); // Will be first index if first to pick up
			IsAPlayerHolding = true;
		} else // If a Player is already holding the object
		{
			//Mesh->SetMobility(EComponentMobility::Type::Movable);
			//SetLockLocation(false);
			Mesh->BodyInstance.bLockRotation = true;
			SetActorEnableCollision(false);
			this->AttachToComponent(
			Player->GetMesh(),
			FAttachmentTransformRules
			(EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			true),
			"Hand_Pos");
			PlayersHolding.Add(Player);
			// PlayersHolding[0]->SetLockLocation(false);
			PlayersHolding[0]->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		}
	}
	
}

void APickUpObject::StartPickUp(ACouchGame2025Character* Player) {

	// Will only be called when a single player is needed to pick up the object
	
	Interactor = Player;
	this->AttachToComponent(
		Player->GetMesh(),
		FAttachmentTransformRules
		(
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true
		),
		"Hand_Pos"
		);
	
	SetActorEnableCollision(false);
	Mesh->BodyInstance.bLockRotation = true;
}

void APickUpObject::StopPickUp()
{
	if (PlayersHolding.Num() < 2)
	{
		PlayersHolding[0]->SetLockLocation(false);
	}
	
	this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetActorEnableCollision(true);
	Mesh->BodyInstance.bLockRotation = false;
}

// Called every frame
void APickUpObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}