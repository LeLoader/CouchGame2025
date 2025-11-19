	#include "Gameplay/TransferPoint.h"
	#include "Components/SphereComponent.h"
	#include "Engine/Engine.h"
	
	ATransferPoint::ATransferPoint()
	{
	    PrimaryActorTick.bCanEverTick = true;
	    InternalPlanet = nullptr;
	}
	
	void ATransferPoint::BeginPlay()
	{
	    Super::BeginPlay();
	
	    if (Bp_Planet)
	    {
	        InternalPlanet = Bp_Planet->FindComponentByClass<USphereComponent>();
	        if (!InternalPlanet)
	        {
	            UE_LOG(LogTemp, Warning, TEXT("ATransferPoint: Bp_Planet does not contain a USphereComponent."));
	        }
	        else
	        {
		        UE_LOG(LogTemp, Log, TEXT("ATransferPoint: Successfully found USphereComponent in Bp_Planet. %d"), InternalPlanet);
	        }
	    }
	    else
	    {
	        UE_LOG(LogTemp, Warning, TEXT("ATransferPoint: Bp_Planet is null."));
	    }
	}
	
	void ATransferPoint::Tick(float DeltaTime)
	{
	    Super::Tick(DeltaTime);
	}