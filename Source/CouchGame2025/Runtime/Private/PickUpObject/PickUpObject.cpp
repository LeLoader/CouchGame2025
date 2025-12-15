// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpObject/PickUpObject.h"

#include <string>


#include "CouchGame2025/Runtime/Public/Component/ObjectPlanetaryGravityComponent.h"
#include "CouchGame2025/Runtime/Public/Component/PickupComponent.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Gameplay/Iceseed.h"
#include "Logging/StructuredLog.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "PickUpObject/Lamp.h"


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

// Interact - partie où le deuxième joueur saisit l'objet (modifiée)
bool APickUpObject::Interact(ACouchGame2025Character* Player)
{
	if (Player == nullptr && !bCanBePickedUp) return false;

	if (!NeedsTwoPlayersToBePickedUp)
	{
		StartPickUp(Player);
		return true;
	}
	else
	{
		if (!bIsAPlayerHolding) { // If Player is the first one to hold the object
			Mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
			Player->GetCharacterMovement()->SetMovementMode(MOVE_None);
			Player->bIsGrabbing = true;
			PlayersHolding.Add(Player); // Will be first index if first to pick up
			bIsAPlayerHolding = true;
			return true;
		}
		else // If a Player is already holding the object
		{
			bIsGrabbedByBoth = true;

			// Lock rotation + translations and disable physics to avoid drift
			Mesh->BodyInstance.bLockRotation = true;
			Mesh->BodyInstance.bLockXTranslation = true;
			Mesh->BodyInstance.bLockYTranslation = true;
			Mesh->BodyInstance.bLockZTranslation = true;
			Mesh->SetSimulatePhysics(false);
			//Mesh->SetEnableGravity(false);
			Mesh->SetAllPhysicsLinearVelocity(FVector::ZeroVector);
			Mesh->SetAllPhysicsAngularVelocityInDegrees(FVector::ZeroVector);

			SetActorEnableCollision(false);
			Player->bIsGrabbing = true;
			this->AttachToComponent(
				Player->GetMesh(),
				FAttachmentTransformRules
				(EAttachmentRule::SnapToTarget,
					EAttachmentRule::SnapToTarget,
					EAttachmentRule::KeepWorld,
					true),
				"Throw_Pos");
			PlayersHolding.Add(Player);
			PlayersHolding[0]->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
			this->AttachToComponent(
				PlayersHolding[0]->GetMesh(),
				FAttachmentTransformRules
				(EAttachmentRule::SnapToTarget,
					EAttachmentRule::SnapToTarget,
					EAttachmentRule::KeepWorld,
					true),
				"Throw_Pos");
			return true;
		}
	}
}

// StartPickUp - verrouille la physique et les translations/rotations
void APickUpObject::StartPickUp(ACouchGame2025Character* Player) {

	// Will only be called when a single player is needed to pick up the object
	if (Interactor != nullptr && Interactor->bIsGrabbedByAnotherPlayer) return;
	
	Interactor = Player;
	Interactor->bIsGrabbing = true;
	Interactor->PickupComponent->PickedUpObject = this;
	PlayersHolding.Add(Player);
	if (Cast<ALamp>(this))
	{
		this->AttachToComponent(
			Player->GetMesh(),
			FAttachmentTransformRules
			(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::KeepWorld,
				EAttachmentRule::KeepWorld,
				true
			),
			"Throw_Pos"
		);
	}
	else if (Cast<AIceSeed>(this))
	{
		AIceSeed* Ice = Cast<AIceSeed>(this);
		if (Ice && Ice->bFirstTimeGrabbingIceSeed)
		{
			Bp_OnIceHearthPick();
			Ice->bFirstTimeGrabbingIceSeed = false;
		}
		this->AttachToComponent(
			Player->GetMesh(),
			FAttachmentTransformRules
			(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::KeepWorld,
				true
			),
			"Throw_Pos"
		);
	}
	else {
		this->AttachToComponent(
			Player->GetMesh(),
			FAttachmentTransformRules
			(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::KeepWorld,
				true
			),
			"Throw_Pos"
		);
	}
	// Attach and snap location, rotation and scale to the socket

	// Disable collision/physics and lock translations + rotation to keep relative transform fixed
	SetActorEnableCollision(false);

	// Disable physics + gravity and zero velocities to prevent drift
	Mesh->SetSimulatePhysics(false);
	//Mesh->SetEnableGravity(false);
	Mesh->SetAllPhysicsLinearVelocity(FVector::ZeroVector);
	Mesh->SetAllPhysicsAngularVelocityInDegrees(FVector::ZeroVector);

	// Lock translations and rotation on the body instance
	// Mesh->BodyInstance.bLockXTranslation = true;
	// Mesh->BodyInstance.bLockYTranslation = true;
	// Mesh->BodyInstance.bLockZTranslation = true;
	// Mesh->BodyInstance.bLockRotation = true;
	TriggerParticule();
}

// StopPickUp - déverrouille la physique et restaure le comportement précédent
void APickUpObject::StopPickUp(ACouchGame2025Character* Player)
{
	if (PlayersHolding.IsEmpty() || PlayersHolding.Num() == 2 || PlayersHolding.Num() == 0) return;
	if (ALamp* Lamp = Cast<ALamp>(this))
	{
		Lamp->DisableLamp();
		this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		// Réactiver collision et physique
		SetActorEnableCollision(true);

		// Réactiver la simulation physique et la gravité
		Mesh->SetSimulatePhysics(true);

		Player->bIsGrabbing = false;
		PlayersHolding.Empty();
		TriggerParticule();
		Player->PickupComponent->PickedUpObject = nullptr;

		return;
	}
	Player->PickupComponent->PickedUpObject = nullptr;

	PlayersHolding[0]->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	PlayersHolding[0]->bIsGrabbing = false;
	PlayersHolding.Empty();
	this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	// Réactiver collision et physique
	SetActorEnableCollision(true);

	// Réactiver la simulation physique et la gravité
	Mesh->SetSimulatePhysics(true);
	//Mesh->WakeAllRigidBodies();
	FVector FwdVector = Player->GetActorForwardVector();
	Mesh->SetAllPhysicsLinearVelocity(FVector(
		Player->FrontLaunchForce * FwdVector.X,
		Player->FrontLaunchForce * FwdVector.Y,
		Player->FrontLaunchForce * FwdVector.Z) * LaunchForce);
	//SetActorEnableCollision(false);

	// Déverrouiller translations/rotation
	// Mesh->SetConstraintMode(EDOFMode::Type::SixDOF);
	// Mesh->BodyInstance.bLockRotation = false;
	// Mesh->BodyInstance.bLockXTranslation = false;
	// Mesh->BodyInstance.bLockYTranslation = false;
	// Mesh->BodyInstance.bLockZTranslation = false;

	bIsGrabbedByBoth = false;
	bIsAPlayerHolding = false;


	
	//Mesh->AddImpulseAtLocation((FVector(
	//	Player->FrontLaunchForce * FwdVector.X,
	//	Player->FrontLaunchForce * FwdVector.Y,
	//	Player->FrontLaunchForce * FwdVector.Z) * LaunchForce),
	//	GetActorLocation());
	//
	//FTimerHandle TimerHandle;
	//GetWorldTimerManager().SetTimer(TimerHandle, this, &APickUpObject::EnableCollision, .2f, false);
	
	Player->bIsGrabbing = false;
	TriggerParticule();
}

// ReleaseObjectFromOnePlayer - déverrouille également quand un joueur relâche et un autre reste
void APickUpObject::ReleaseObjectFromOnePlayer(ACouchGame2025Character* PlayerReleasing)
{
	Mesh->BodyInstance.bLockRotation = false;
	Mesh->BodyInstance.bLockXTranslation = false;
	Mesh->BodyInstance.bLockYTranslation = false;
	Mesh->BodyInstance.bLockZTranslation = false;

	SetActorEnableCollision(true);
	PlayerReleasing->bIsGrabbing = false;
	int PlayerReleasingIndex = PlayersHolding.Find(PlayerReleasing);
	PlayersHolding.RemoveAt(PlayerReleasingIndex);
	this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	if (PlayersHolding.Num() > 0)
	{
		this->AttachToComponent(
			PlayersHolding[0]->GetMesh(),
			FAttachmentTransformRules
			(EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				true),
			"Hand_Pos");
		PlayersHolding[0]->GetCharacterMovement()->SetMovementMode(MOVE_None);

		// Si un joueur reste, on lock encore l'objet pour qu'il reste fixé
		Mesh->SetSimulatePhysics(false);
		// Mesh->SetEnableGravity(false);
		Mesh->BodyInstance.bLockRotation = true;
		Mesh->BodyInstance.bLockXTranslation = true;
		Mesh->BodyInstance.bLockYTranslation = true;
		Mesh->BodyInstance.bLockZTranslation = true;
		bIsGrabbedByBoth = false;
	}
	else
	{
		// Aucun joueur restant : réactiver la physique
		Mesh->SetSimulatePhysics(true);
		// Mesh->SetEnableGravity(true);
		Mesh->BodyInstance.bLockRotation = false;
		bIsGrabbedByBoth = false;
	}
}

void APickUpObject::EnableCollision()
{
	SetActorEnableCollision(true);
}

int APickUpObject::GetPriority()
{
	return 10;
}

bool APickUpObject::CanBeInteractWithSomethingInHand()
{
	return false;
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
