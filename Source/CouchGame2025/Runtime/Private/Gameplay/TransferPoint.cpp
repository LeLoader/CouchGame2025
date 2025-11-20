#include "CouchGame2025/Runtime/Public/Gameplay/TransferPoint.h"
	#include "Components/SphereComponent.h"
	#include "Engine/Engine.h"
	#include "Kismet/GameplayStatics.h"
	#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
	#include "GameFramework/CharacterMovementComponent.h"
	
	ATransferPoint::ATransferPoint()
	{
	    PrimaryActorTick.bCanEverTick = true;
	    InternalPlanet = nullptr;
	
	    TransferPointCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TransferPointCapsule"));
	    TransferPointCapsule->SetupAttachment(RootComponent);
	
	    SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("TransferSpline"));
	    SplineComponent->SetupAttachment(RootComponent);
	}
	
	void ATransferPoint::BeginPlay()
	{
	    Super::BeginPlay();
	
	    if (Bp_Planet)
	    {
	        InternalPlanet = Bp_Planet->FindComponentByClass<USphereComponent>();
	    }
	}

	
	void ATransferPoint::Tick(float DeltaTime)
	{
	    Super::Tick(DeltaTime);
		
	}