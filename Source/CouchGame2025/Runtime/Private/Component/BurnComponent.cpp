


#include "Component/BurnComponent.h"

#include "Interface/Burnable.h"
#include "Global/CouchGame2025Character.h"
#include "Gameplay/Iceseed.h"


// Sets default values for this component's properties
UBurnComponent::UBurnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


void UBurnComponent::StartBurn(ACouchGame2025Character* Instigator)
{
	BurnInstigators.Add(Instigator);
	if (BurnInstigators.Num() >= NumOfSourceToBurn) {
		OnBurnStarted.Broadcast();
	}
}

void UBurnComponent::StopBurn(ACouchGame2025Character* Instigator)
{
	BurnInstigators.Remove(Instigator);
}

void UBurnComponent::AddFakeBurnSource()
{
	BurnInstigators.Add(nullptr);
	if (BurnInstigators.Num() >= NumOfSourceToBurn) {
	OnBurnStarted.Broadcast();
	}
}

void UBurnComponent::RemoveFakeBurnSource()
{
	BurnInstigators.Remove(nullptr);
}

void UBurnComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<IBurnable>(GetOwner());
	if (Owner == nullptr) {
		DestroyComponent();
	}
}

// Called every frame
void UBurnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (BurnInstigators.Num() >= NumOfSourceToBurn) {
		Owner->Burn(DeltaTime);
	}
}

