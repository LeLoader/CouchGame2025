#include "Gameplay/TransferPoint.h"

#include "CableComponentBis.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"
#include "Components/BoxComponent.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "Components/SplineComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CouchGame2025/Editor/Public/TransfertSettings.h"
#include "Gameplay/PlayerConstraint.h"


#define ECC_Interactable ECC_GameTraceChannel2

ATransfertPoint::ATransfertPoint()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Capsule"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	RootComponent = BoxComponent;
	CameraComponent->SetupAttachment(RootComponent);
}

int ATransfertPoint::GetPriority()
{
	return 5;
}

bool ATransfertPoint::CanBeInteractWithSomethingInHand()
{
	return true;
}

void ATransfertPoint::BeginPlay()
{
	Super::BeginPlay();
	TransfertSettings = GetDefault<UTransfertSettings>();
}	

void ATransfertPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ATransfertPoint::Interact(ACouchGame2025Character* Player)
{
		if (!bOnePlayerHasAlreadyInteracted)
		{
			bOnePlayerHasAlreadyInteracted = true;
			FirstInstigator = Player;
			Player->Wait();
			Player->SetSpecialCameraAsCamera(1.f, this);
		}
		else {
			if (Player == FirstInstigator)
			{
				Player->StopWait();
				FirstInstigator = nullptr;
				bOnePlayerHasAlreadyInteracted = false;
				Player->SetGameplayCameraAsCamera(1.f);
			}
			else if (Player->bIsAttachedToRope)
			{
				Player->Wait();
				FirstInstigator->MoveAlongSpline(Spline, IsExtern);
				FirstInstigator->OnEndMovingAlongSpline.AddUObject(this, &ATransfertPoint::OnMovementAlongSplineOver);
				SecondInstigator = Player;
				bOnePlayerHasAlreadyInteracted = false;
				BoxComponent->SetCollisionResponseToChannel(ECC_Interactable, ECollisionResponse::ECR_Ignore);
				Player->SetSpecialCameraAsCamera(TransfertSettings->CharacterTransfertTime * 2, LinkedPoint);
				FirstInstigator->SetRespawnLocation(LinkedPoint->RespawnPoint);
				SecondInstigator->SetRespawnLocation(LinkedPoint->RespawnPoint);
				return true;
			}
		}
	return false;
}

void ATransfertPoint::SetSplineComponent(USplineComponent* InSpline)
{
	Spline = InSpline;
}

void ATransfertPoint::SetRespawnLocation(FVector InLocation)
{
	RespawnPoint = InLocation;
}

void ATransfertPoint::OnMovementAlongSplineOver()
{
	if (FirstInstigator != nullptr)
	{
		FirstInstigator->InvertCamera();
		SecondInstigator->MoveAlongSpline(Spline, IsExtern);
		SecondInstigator->OnEndMovingAlongSpline.AddUObject(this, &ATransfertPoint::OnMovementAlongSplineOver);
		FirstInstigator->OnEndMovingAlongSpline.RemoveAll(this);
		FirstInstigator->StopWait();
		FirstInstigator = nullptr;
		return;
	}
	if (SecondInstigator != nullptr)
	{
		SecondInstigator->OnEndMovingAlongSpline.RemoveAll(this);
		SecondInstigator->SetGameplayCameraAsCamera(1.f);
		SecondInstigator->StopWait();
		SecondInstigator = nullptr;
		BoxComponent->SetCollisionResponseToChannel(ECC_Interactable, ECollisionResponse::ECR_Block);
		return;
	}
}

void ATransfertPoint::SetLinkedActor(AActor* InActor)
{
	if (ATransfertPoint* Point = Cast<ATransfertPoint>(InActor))
	{
		LinkedPoint = Point;
	}
}