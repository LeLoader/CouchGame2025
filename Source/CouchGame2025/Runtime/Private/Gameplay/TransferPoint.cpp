#include "Gameplay/TransferPoint.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"
#include "Components/BoxComponent.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "Components/SplineComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

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

void ATransfertPoint::BeginPlay()
{
	Super::BeginPlay();
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
			Player->bIsWaiting = true;
			UGameplayStatics::GetPlayerController(this, 0)->SetViewTargetWithBlend(this, 1.f, EViewTargetBlendFunction::VTBlend_Cubic, 0.5f);
		}
		else {
			if (Player == FirstInstigator)
			{
				FirstInstigator->bIsWaiting = false;
				FirstInstigator = nullptr;
				bOnePlayerHasAlreadyInteracted = false;
				Player->SetGameplayCameraAsCamera(1.f);
			}
			else
			{
				//FirstInstigator->InvertCamera();
				FirstInstigator->MoveAlongSpline(Spline, IsExtern);
				FirstInstigator->OnEndMovingAlongSpline.AddUObject(this, &ATransfertPoint::OnMovementAlongSplineOver);
				SecondInstigator = Player;
				bOnePlayerHasAlreadyInteracted = false;
				BoxComponent->SetCollisionResponseToChannel(ECC_Interactable, ECollisionResponse::ECR_Ignore);
				Player->SetSpecialCameraAsCamera(1.5f, LinkedPoint);
				return true;
			}
		}
	return false;
}

void ATransfertPoint::SetSplineComponent(USplineComponent* InSpline)
{
	Spline = InSpline;
}

void ATransfertPoint::OnMovementAlongSplineOver()
{
	if (FirstInstigator != nullptr)
	{
		FirstInstigator->InvertCamera();
		SecondInstigator->MoveAlongSpline(Spline, IsExtern);
		SecondInstigator->OnEndMovingAlongSpline.AddUObject(this, &ATransfertPoint::OnMovementAlongSplineOver);
		FirstInstigator->OnEndMovingAlongSpline.RemoveAll(this);
		FirstInstigator = nullptr;
		return;
	}
	if (SecondInstigator != nullptr)
	{
		SecondInstigator->OnEndMovingAlongSpline.RemoveAll(this);
		SecondInstigator->SetGameplayCameraAsCamera(1.f);
		SecondInstigator = nullptr;
		BoxComponent->SetCollisionResponseToChannel(ECC_Interactable, ECollisionResponse::ECR_Block);
		return;
	}
}

void ATransfertPoint::SetLinkedActor(AActor* InActor)
{
	LinkedPoint = InActor;
}