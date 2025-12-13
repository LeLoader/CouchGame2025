#include "CouchGame2025/Runtime/Public/Gameplay/CouchCameraActor.h"
#include "CouchGame2025/Runtime/Public/Gameplay/InterestPoint.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Math/UnrealMathUtility.h"

ACouchCameraActor* ACouchCameraActor::CurrentCamera = nullptr;

ACouchCameraActor::ACouchCameraActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 400.f;
	GetCameraComponent()->SetupAttachment(SpringArmComponent);
}

void ACouchCameraActor::PolarToCartesian(float r, float theta, float phi, FVector& OutVector)
{
	OutVector.X = r * FMath::Sin(theta) * FMath::Cos(phi);
	OutVector.Y = r * FMath::Sin(theta) * FMath::Sin(phi);
	OutVector.Z = r * FMath::Cos(theta);
}

void ACouchCameraActor::CartesianToPolar(FVector Vector, float& OutR, float& OutTheta, float& OutPhi)
{
	OutR = Vector.Length();
	OutTheta = FMath::Acos(Vector.Z / OutR);
	OutPhi = FMath::Atan2(Vector.Y, Vector.X);
}

void ACouchCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentPositionPolar.Theta = FMath::FInterpTo(CurrentPositionPolar.Theta, TargetPositionPolar.Theta, DeltaTime, LerpSpeed);
	CurrentPositionPolar.Phi = FMath::FInterpTo(CurrentPositionPolar.Phi, TargetPositionPolar.Phi, DeltaTime, LerpSpeed);
	FVector NewPosition;
	PolarToCartesian(CurrentPositionPolar.Radius, CurrentPositionPolar.Theta, CurrentPositionPolar.Phi, NewPosition);
	SetActorLocation(NewPosition);
}

void ACouchCameraActor::BeginPlay()
{
	Super::BeginPlay();
	ACouchCameraActor::CurrentCamera = this;
	CartesianToPolar(GetActorLocation(), CurrentPositionPolar.Radius, CurrentPositionPolar.Theta, CurrentPositionPolar.Phi);
	CartesianToPolar(GetActorLocation(), TargetPositionPolar.Radius, TargetPositionPolar.Theta, TargetPositionPolar.Phi);

}

void ACouchCameraActor::Move(FVector2D Input)
{
	CartesianToPolar(GetActorLocation(), CurrentPositionPolar.Radius, CurrentPositionPolar.Theta, CurrentPositionPolar.Phi);
	if (bIsInverted)
	{
		TargetPositionPolar.Theta = TargetPositionPolar.Theta + Input.Y * PI / 180;
	}
	else
	{
		TargetPositionPolar.Theta = TargetPositionPolar.Theta - Input.Y * PI / 180;
	}
	TargetPositionPolar.Theta = FMath::Clamp(TargetPositionPolar.Theta, 0.1f, PI - 0.1f);
	TargetPositionPolar.Phi = TargetPositionPolar.Phi + Input.X * PI / 180;
}

void ACouchCameraActor::Zoom(float Input)
{
	float R = 0.f;
	float Theta = 0.f;
	float Phi = 0.f;
	CartesianToPolar(GetActorLocation(), R, Theta, Phi);
	if (bIsInverted)
	{
		R += Input * 50.f;
		R = FMath::Clamp(R, 2500.f, 3500.f);	
	}
	else
	{
		R -= Input * 50.f;
		R = FMath::Clamp(R, 7000.f, 9000.f);
	}
	FVector NewPosition;
	PolarToCartesian(R, Theta, Phi, NewPosition);
	SetActorLocation(NewPosition);
}

void ACouchCameraActor::InvertCamera()
{
	if (bIsInverted)
	{
		CurrentPositionPolar.Radius = 8000.f;
		TargetPositionPolar.Radius = 8000.f;
	}
	else
	{
		CurrentPositionPolar.Radius = InternDistance;
		TargetPositionPolar.Radius = InternDistance;
	}
	FVector NewPosition;
	PolarToCartesian(CurrentPositionPolar.Radius, CurrentPositionPolar.Theta, CurrentPositionPolar.Phi, NewPosition);
	SetActorLocation(NewPosition);
	bIsInverted = !bIsInverted;
	ToggleBlackHole();
}

ACouchCameraActor* ACouchCameraActor::GetCurrentCamera()
{
	return ACouchCameraActor::CurrentCamera;
}