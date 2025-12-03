#include "CouchGame2025/Runtime/Public/Component/RessourceContainerComponent.h"



// Sets default values for this component's properties
URessourceContainerComponent::URessourceContainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URessourceContainerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	

}


// Called every frame
void URessourceContainerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!TargetContainers.IsEmpty()) {
		for (URessourceContainerComponent* TargetRessourceContainer : TargetContainers) {
			InstantMoveRessource(DeltaTime, TargetRessourceContainer);
		}
	}
}

float URessourceContainerComponent::AddRessource(float Amount)
{
	if (Amount < UE_KINDA_SMALL_NUMBER) return 0.f;

	float OldRessourceAmount = CurrentRessourceAmount;
	CurrentRessourceAmount = FMath::Clamp(CurrentRessourceAmount + Amount, 0, MaxRessourceAmount);
	OnRessourceUpdated.Broadcast(CurrentRessourceAmount, OldRessourceAmount);
	
	if (IsContainerFull()) {
		OnContainerFull.Broadcast();
		OnContainerFullBP.Broadcast();
	}
	return CurrentRessourceAmount - OldRessourceAmount;
}

float URessourceContainerComponent::RemoveRessource(float Amount)
{
	if (Amount < UE_KINDA_SMALL_NUMBER) return 0.f;

	float OldRessourceAmount = CurrentRessourceAmount;
	CurrentRessourceAmount = FMath::Clamp(CurrentRessourceAmount - Amount, 0, MaxRessourceAmount);
	OnRessourceUpdated.Broadcast(CurrentRessourceAmount, OldRessourceAmount);
	if (IsContainerEmpty()) {
		OnContainerEmpty.Broadcast();
		OnContainerEmptyBP.Broadcast();
	}
	return OldRessourceAmount - CurrentRessourceAmount;
}

float URessourceContainerComponent::InstantMoveRessource(float DeltaTime, URessourceContainerComponent* Target)
{

	// Target is a valid container, move ressource inside Target
	if (IsValid(Target)) {
		if (Target->IsContainerFull() || IsContainerEmpty() || Target->RessourceType != RessourceType) return 0;

		float RessourceRemoved = this->RemoveRessource(DeltaTime);
		float RessourceAdded = Target->AddRessource(RessourceRemoved);
		float OverflowDuringTransaction = RessourceRemoved - RessourceAdded;
		AddRessource(OverflowDuringTransaction);

		return RessourceAdded;
	}
	// Target is not valid, destroy ressource
	else {
		if (IsContainerEmpty()) return 0;
		float RessourceRemoved = this->RemoveRessource(DeltaTime);
		return RessourceRemoved;
	}
}

void URessourceContainerComponent::StartMovingRessource(URessourceContainerComponent* Target)
{
	if (Target->RessourceType == RessourceType) {
		TargetContainers.AddUnique(Target);
	}
}

void URessourceContainerComponent::StopMovingRessource(URessourceContainerComponent* Target)
{
	if (Target->RessourceType == RessourceType) {
		TargetContainers.Remove(Target);
	}
}

