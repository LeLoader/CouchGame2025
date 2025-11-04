// Fill out your copyright notice in the Description page of Project Settings.


#include "CouchGame2025/Runtime/Public/PickUpObject/PickUpObject.h"

#include <string>


#include "CouchGame2025/Runtime/Public/Component/PickupComponent.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
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

	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), )
	
}

void APickUpObject::Interact(ACouchGame2025Character* Player)
{
	//passe	

	if (Player == nullptr) return;
	StartPickUp(Player);

}

void APickUpObject::StartPickUp(ACouchGame2025Character* Player) {
	Interactor = Player;
	SetActorEnableCollision(false);
	// Mesh->SetPhysicsAngularVelocityInDegrees(FVector(0, 0, 0));
	// Mesh->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	// Mesh->SetWorldRotation(FRotator(0, 0, 0));
	// Mesh->BodyInstance.bLockRotation = true;
	Player->PickupComponent->IsGrabbingObject = true;
	// Player->PickupComponent->PhysicsHandle->Activate(true);
}

void APickUpObject::StopPickUp()
{
	SetActorEnableCollision(true);
	if (Socket == nullptr) {
		return; // :)
	}
	float DistToSocket = FVector::Dist(Socket->GetActorLocation(), GetActorLocation());

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("%f"), DistToSocket);
	UE_LOGFMT(LogTemplateCharacter, Log, "Distance : {0}", DistToSocket);

	if (DistToSocket <= 150.f)
	{
		SetActorLocation(Socket->GetActorLocation() + FVector::UpVector * 50);
		SetActorRotation(Socket->GetActorRotation());
		Mesh->BodyInstance.bLockRotation = false;
	}

}


// Called every frame
void APickUpObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

