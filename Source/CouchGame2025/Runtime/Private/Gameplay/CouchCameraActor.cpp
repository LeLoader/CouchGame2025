#include "CouchGame2025/Runtime/Public/Gameplay/CouchCameraActor.h"
#include "CouchGame2025/Runtime/Public/Gameplay/InterestPoint.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Math/UnrealMathUtility.h"


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
	GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::White, TEXT("Theta : ") + FString::SanitizeFloat(OutTheta));
	GEngine->AddOnScreenDebugMessage(2, 3.f, FColor::White, TEXT("Phi : ") + FString::SanitizeFloat(OutPhi));
	GEngine->AddOnScreenDebugMessage(3, 3.f, FColor::White, TEXT("Y : ") + FString::SanitizeFloat(Vector.Y));
	GEngine->AddOnScreenDebugMessage(4, 3.f, FColor::White, TEXT("X : ") + FString::SanitizeFloat(Vector.X));
}

void ACouchCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector LookAtPosition = CalculateAveragePositions();
	float Zoom = 750.f;
	FVector CameraDestination = LookAtPosition;
	LookAtPosition.Normalize();
	CameraDestination += Zoom * LookAtPosition;
	DrawDebugSphere(GetWorld(), CameraDestination, 16, 32, FColor::Red, false, -1.f, 32);
	float TargetR = 0.f;
	float TargetTheta = 0.f;
	float TargetPhi = 0.f;
	CartesianToPolar(CameraDestination, TargetR, TargetTheta, TargetPhi);
	float CurrentR = 0.f;
	float CurrentTheta = 0.f;
	float CurrentPhi = 0.f;
	CartesianToPolar(GetActorLocation(), CurrentR, CurrentTheta, CurrentPhi);
	CurrentR = FMath::FInterpTo(CurrentR, TargetR, DeltaTime, LerpSpeed);
	CurrentTheta = FMath::FInterpTo(CurrentTheta, TargetTheta, DeltaTime, LerpSpeed);
	CurrentPhi = FMath::FInterpTo(CurrentPhi, TargetPhi, DeltaTime, LerpSpeed);
	FVector NewPosition;
	PolarToCartesian(CurrentR, CurrentTheta, CurrentPhi, NewPosition);
	SetActorLocation(NewPosition);
	//FVector NewRotationToLookAt = FMath::VInterpTo(GetCameraComponent()->GetComponentLocation(), TargetPosition, DeltaTime, 0.7f);
	//SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), NewRotationToLookAt));
}

void ACouchCameraActor::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> Points;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInterestPoint::StaticClass(), Points);
	for (AActor* Point : Points)
	{
		AInterestPoint* CurrentPoint = Cast<AInterestPoint>(Point);
		if (CurrentPoint != nullptr)
		{
			CurrentPoint->OnInfluenceZoneEnteredEvent.AddDynamic(this, &ACouchCameraActor::ChangeDestination);
		}
	}
}

void ACouchCameraActor::ChangeDestination(AInterestPoint* NewInterestPoint)
{
	CurrentInterestPoint = NewInterestPoint;
}

void ACouchCameraActor::SetCharacters(AActor* FirstCharacter, AActor* SecondCharacter)
{
	Characters.Add(FirstCharacter);
	Characters.Add(SecondCharacter);
}

FVector ACouchCameraActor::CalculateAveragePositions()
{
	FVector FinalPosition = FVector::ZeroVector;
	if (Characters.IsEmpty()) return GetActorLocation();
	int TotalPoints = 0;
	for (AActor* Character : Characters)
	{
		FinalPosition += Character->GetActorLocation();
		TotalPoints++;
	}
	if (CurrentInterestPoint != nullptr)
	{
		FinalPosition += CurrentInterestPoint->GetActorLocation();
		TotalPoints++;
	}
	return FinalPosition / TotalPoints;
}

void ACouchCameraActor::Move(FVector2D Input)
{
	float R = 0.f;
	float Theta = 0.f;
	float Phi = 0.f;
	CartesianToPolar(GetActorLocation(), R, Theta, Phi);
	Theta -= Input.Y * PI / 180;
	Theta = FMath::Clamp(Theta, 0.1f, PI - 0.1f);
	Phi += Input.X * PI / 180;
	FVector NewPosition;
	PolarToCartesian(R, Theta, Phi, NewPosition);
	SetActorLocation(NewPosition);
}

void ACouchCameraActor::Zoom(float Input)
{
	float R = 0.f;
	float Theta = 0.f;
	float Phi = 0.f;
	CartesianToPolar(GetActorLocation(), R, Theta, Phi);
	R -= Input * 50.f;
	R = FMath::Clamp(R, 7000.f, 9000.f);
	FVector NewPosition;
	PolarToCartesian(R, Theta, Phi, NewPosition);
	SetActorLocation(NewPosition);
}

//{
//	average des joueurs : LookAtPos
//	float Zoom entre camera et LookAtPos : Zoom
//	Vector unitaire : UP du World
//	TargetLocation : LookAtPos + Zoom * vector unitaire
//	COORD Polaire de TargetLocation
//
//}