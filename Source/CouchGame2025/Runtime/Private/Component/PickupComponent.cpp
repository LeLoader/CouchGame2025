// Fill out your copyright notice in the Description page of Project Settings.


#include "CouchGame2025/Runtime/Public/Component/PickupComponent.h"

#include "KismetTraceUtils.h"


// Sets default values for this component's properties
UPickupComponent::UPickupComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickupComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPickupComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPickupComponent::TryPickUp()
{
	FHitResult* Hit = new FHitResult();
	FVector StartLocation = GetOwner()->GetActorLocation();
	FVector EndLocation = StartLocation + GetOwner()->GetActorForwardVector()*250;
	
	GetWorld()->LineTraceSingleByChannel(*Hit, StartLocation, EndLocation, ECC_Visibility);
	
	if (Hit->bBlockingHit == true && IsValid(Hit->GetActor()))
	{
		DrawDebugLine(GetWorld(), StartLocation, Hit->Location, FColor::Red);
		DrawDebugSphere(GetWorld(), Hit->Location, 5, 5, FColor::White);

		AActor* PickedActor = Hit->GetActor();

		//bool IsActorPickable = 
		
		GEngine->AddOnScreenDebugMessage(
			-1,
			3.f,
			FColor::Cyan,
			PickedActor->GetName());
	} else
	{
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red);
		DrawDebugSphere(GetWorld(), EndLocation, 5, 5, FColor::White);
		GEngine->AddOnScreenDebugMessage(
			-1,
			3.f,
			FColor::Cyan,
			TEXT("Not Found"));
	}
	
}

