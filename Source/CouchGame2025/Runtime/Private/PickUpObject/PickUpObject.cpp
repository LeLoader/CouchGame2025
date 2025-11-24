// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpObject/PickUpObject.h"

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
	bIsPickedUp = false;
	bIsGrabbedByBoth = false;
}

bool APickUpObject::Interact(ACouchGame2025Character* Player)
{
	if (Player == nullptr) return false;

	if (!NeedsTwoPlayersToBePickedUp)
	{
		StartPickUp(Player);
	}
	else
	{
		// If two players are needed to move the object around
		
		if (!bIsAPlayerHolding){ // If Player is the first one to hold the object
			Mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
			Player->GetCharacterMovement()->SetMovementMode(MOVE_None);
			Player->bIsGrabbing = true;
			// this->AttachToComponent(
			// Player->GetMesh(),
			// FAttachmentTransformRules
			// (EAttachmentRule::SnapToTarget,
			// EAttachmentRule::SnapToTarget,
			// EAttachmentRule::SnapToTarget,
			// true),
			// "Hand_Pos");
			PlayersHolding.Add(Player); // Will be first index if first to pick up
			bIsAPlayerHolding = true;
		} else // If a Player is already holding the object
		{
			bIsGrabbedByBoth = true;
			Mesh->BodyInstance.bLockRotation = true;
			SetActorEnableCollision(false);
			Player->bIsGrabbing = true;
			this->AttachToComponent(
			Player->GetMesh(),
			FAttachmentTransformRules
			(EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			true),
			"Hand_Pos");
			PlayersHolding.Add(Player);
			PlayersHolding[0]->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
			this->AttachToComponent(
				PlayersHolding[0]->GetMesh(),
				FAttachmentTransformRules
				(EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				true),
				"Hand_Pos");
		}
	}
	return true;
}

void APickUpObject::StartPickUp(ACouchGame2025Character* Player) {

	// Will only be called when a single player is needed to pick up the object
	
	Interactor = Player;
	Interactor->bIsGrabbing = true;
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

void APickUpObject::StopPickUp(ACouchGame2025Character* Player)
{
	if (PlayersHolding.Num() < 2)
	{
		PlayersHolding[0]->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		PlayersHolding[0]->bIsGrabbing = false;
		PlayersHolding.Empty();
		this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		SetActorEnableCollision(true);
		Mesh->BodyInstance.bLockRotation = false;
		bIsGrabbedByBoth = false;
		bIsAPlayerHolding = false;
		return;
	}
	ReleaseObjectFromOnePlayer(Player);
}

// Called every frame

void APickUpObject::ReleaseObjectFromOnePlayer(ACouchGame2025Character* PlayerReleasing)
{
	Mesh->BodyInstance.bLockRotation = false;
	SetActorEnableCollision(true);
	PlayerReleasing->bIsGrabbing = false;
	int PlayerReleasingIndex = PlayersHolding.Find(PlayerReleasing);
	PlayersHolding.RemoveAt(PlayerReleasingIndex);
	this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	
	this->AttachToComponent(
	PlayersHolding[0]->GetMesh(),
	FAttachmentTransformRules
	(EAttachmentRule::SnapToTarget,
	EAttachmentRule::SnapToTarget,
	EAttachmentRule::SnapToTarget,
	true),
	"Hand_Pos");
	PlayersHolding[0]->GetCharacterMovement()->SetMovementMode(MOVE_None);
	bIsGrabbedByBoth = false;
}


void APickUpObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsGrabbedByBoth && PlayersHolding.Num() == 2)
	{
		PlayersAverageInput = (PlayersHolding[0]->InputMovement + PlayersHolding[1]->InputMovement) / 2;
   
		
		for (ACouchGame2025Character* Element : PlayersHolding)
		{
			Element->MoveWhenGrabbing(PlayersAverageInput);
		}
	}
}
