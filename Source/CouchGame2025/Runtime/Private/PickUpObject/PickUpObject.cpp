// Fill out your copyright notice in the Description page of Project Settings.


#include "CouchGame2025/Runtime/Public/PickUpObject/PickUpObject.h"

#include <string>

#include "CouchGame2025/Runtime/Public/Component/PickupComponent.h"
#include "CouchGame2025/Runtime/Public/Component/PlanetaryMovementComponent.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"
#include "Misc/MapErrors.h"
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

	Interactor = Player;
	SetActorEnableCollision(false);
	Player->PickupComponent->IsGrabbingObject = true;
	Player->PickupComponent->PhysicsHandle->Activate(true);
}

void APickUpObject::StopPickUp()
{
	SetActorEnableCollision(true);
	float DistToSocket = FVector::Dist(Socket->GetActorLocation(), GetActorLocation());

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("%f"), DistToSocket);
	UE_LOGFMT(LogTemplateCharacter, Log, "Distance : {0}", DistToSocket);

	if (DistToSocket <= 150.f)
	{
		SetActorLocation(Socket->GetActorLocation() + FVector::UpVector * 50);
	}

}


// Called every frame
void APickUpObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Mesh && Mesh->IsSimulatingPhysics())
	{
		UPlanetaryMovementComponent* PlanetaryComp = nullptr;
		if (Interactor)
		{
			PlanetaryComp = Interactor->FindComponentByClass<UPlanetaryMovementComponent>();
		}

		if (PlanetaryComp)
		{
			FVector ObjectPosition = GetActorLocation();
			FVector GravityDir = (PlanetaryComp->PlanetCenter - ObjectPosition).GetSafeNormal();

			if (!PlanetaryComp->UseExternalGravityDirection)
			{
				GravityDir *= -1;
			}

			float GravityZ = GetWorld()->GetGravityZ();
			FVector GravityForce = GravityDir * FMath::Abs(GravityZ) * Mesh->GetMass();

			Mesh->AddForce(GravityForce);
			UE_LOGFMT(LogTemplateCharacter, Log, "Applying gravity force: {0}", *GravityForce.ToString());
		}
	}
}

