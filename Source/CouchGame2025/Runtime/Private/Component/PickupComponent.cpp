// Fill out your copyright notice in the Description page of Project Settings.


#include "CouchGame2025/Runtime/Public/Component/PickupComponent.h"

#include "KismetTraceUtils.h"
#include "CouchGame2025/Runtime/Public/Interface/Interactable.h"
#include "CouchGame2025/Runtime/Public/PickUpObject/PickUpObject.h"
#include <CouchGame2025/Runtime/Public/Interface/Usable.h>
#include <Logging/StructuredLog.h>


// Sets default values for this component's properties
UPickupComponent::UPickupComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(FName("PhysicsHandle"));
	//PhysicsHandle->AddToRoot();
	
	// ...
}


// Called when the game starts
void UPickupComponent::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<ACouchGame2025Character>(GetOwner());
	if (!IsValid(Player))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Player Is InValid");
	}
}


// Called every frame
void UPickupComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsGrabbingObject)
	{
		PhysicsHandle->SetTargetLocationAndRotation(GetComponentLocation(), GetForwardVector().Rotation());
		DrawDebugSphere(GetWorld(), GetComponentLocation(), 20, 16, FColor::Red);
		DrawDebugLine(GetWorld(), GetComponentLocation(), GetComponentLocation() + GetForwardVector() * 100, FColor::Blue);
		//passe
	}
}

void UPickupComponent::TryPickUp()
{
	if (IsValid(PickedUpObject)) {
		return;
	}

	FHitResult* Hit = new FHitResult();
	FVector StartLocation = GetOwner()->GetActorLocation();
	FVector EndLocation = StartLocation + GetOwner()->GetActorForwardVector() * TraceLength;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Player);
	GetWorld()->SweepSingleByChannel(*Hit, StartLocation, EndLocation, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(TraceWidth));
	
	//GetWorld()->LineTraceSingleByChannel(*Hit, StartLocation, EndLocation, ECC_Visibility);
	DrawDebugSphere(GetWorld(), StartLocation, TraceWidth, 8, FColor::White);
	
	if (Hit->bBlockingHit == true && IsValid(Hit->GetActor()))
	{
		DrawDebugSphere(GetWorld(), Hit->Location, TraceWidth, 8, FColor::Green);

		AActor* PickedActor = Hit->GetActor();

		if (IInteractable* PickupObject = Cast<IInteractable>(PickedActor))
		{
			PickedUpObject = Cast<APickUpObject>(PickedActor);
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, Hit->GetComponent()->GetName());
			PhysicsHandle->GrabComponentAtLocation(Cast<UPrimitiveComponent>(PickedActor->GetRootComponent()), FName(), PickedActor->GetActorLocation());
			PhysicsHandle->Activate();
			PickupObject->Interact(Player);

		} else
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, "Can Not Be Picked up");
		}
		
	} else
	{
		DrawDebugSphere(GetWorld(), EndLocation, TraceWidth, 8, FColor::Red);

		GEngine->AddOnScreenDebugMessage(
			-1,
			3.f,
			FColor::Cyan,
			TEXT("Not Found"));
	}
}

void UPickupComponent::StartUse() {
	if (IUsable* UsableObject = Cast<IUsable>(PickedUpObject)) {
		UsableObject->StartUse();
	}
}

void UPickupComponent::Use() {
	if (IUsable* UsableObject = Cast<IUsable>(PickedUpObject)) {
		UsableObject->Use();
	}
}

void UPickupComponent::StopUse() {
	if (IUsable* UsableObject = Cast<IUsable>(PickedUpObject)) {
		UsableObject->StopUse();
	}
}

void UPickupComponent::HandleInputCompleted() {
	if (!bCanBeReleased)
		bCanBeReleased = true;

	StopPickUp();
}

void UPickupComponent::StopPickUp()
{
	if (!IsValid(PickedUpObject) || !bCanBeReleased) {
		return;
	}

	PickedUpObject->StopPickUp();
	PhysicsHandle->ReleaseComponent();
	PickedUpObject = nullptr;
	IsGrabbingObject = false;
	bCanBeReleased = false;
}

