


#include "PickUpObject/Lamp.h"

#include "Global/CouchGame2025Character.h"
#include "Interface/Burnable.h"
#include "Component/BurnComponent.h"

ALamp::ALamp()
{

}

void ALamp::StartUse()
{
	if (bIsActive) DisableLamp();
	else EnableLamp();
}

void ALamp::Use() {}

void ALamp::StopUse() {}

void ALamp::EnableLamp_Implementation()
{
	bIsActive = true;
}

void ALamp::DisableLamp_Implementation()
{
	bIsActive = false;

	for (IBurnable* OldBurnable : OldBurnTarget) {
		OldBurnable->GetBurnComponent()->StopBurn(Interactor);
	}

	OldBurnTarget.Empty();
	CurrentBurnTarget.Empty();

	bIsActive = false;
}

void ALamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bIsActive) {
		TArray<FHitResult> Hits;
		FVector StartLocation = Interactor->GetActorLocation();
		FVector EndLocation = StartLocation + Interactor->GetActorForwardVector() * FlamethrowerLength;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(Interactor);

		GetWorld()->SweepMultiByChannel(Hits, StartLocation, EndLocation, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(FlamethrowerWidth));

		// Check new burnable target
		for (FHitResult Hit : Hits) {
			if (IBurnable* Burnable = Cast<IBurnable>(Hit.GetActor())) {
				if (!CurrentBurnTarget.Contains(Burnable)) {
					CurrentBurnTarget.AddUnique(Burnable);
					Burnable->GetBurnComponent()->StartBurn(Interactor);
				}
			}
		}

		// Check old burnable target that are not burnable anymore, then override old burn target
		for (IBurnable* OldBurnable : OldBurnTarget) {
			if (!CurrentBurnTarget.Contains(OldBurnable)) {
				OldBurnable->GetBurnComponent()->StopBurn(Interactor);
			}
		}

		OldBurnTarget = CurrentBurnTarget;
	}
}

void ALamp::StartPickUp(ACouchGame2025Character* Player)
{
	Super::StartPickUp(Player);
}

void ALamp::StopPickUp(ACouchGame2025Character* Player)
{
	Super::StopPickUp(Player);

	DisableLamp();
}

void ALamp::BeginPlay()
{
	Super::BeginPlay();
	RespawnLocation = GetActorLocation();
}

void ALamp::RespawnLamp()
{
	SetActorLocation(RespawnLocation);
	DisableLamp();
}