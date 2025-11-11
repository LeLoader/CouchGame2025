


#include "CouchGame2025/Runtime/Public/PickUpObject/Flamethrower.h"

#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include <CouchGame2025/Runtime/Public/Interface/Burnable.h>
#include "Component/BurnComponent.h"

AFlamethrower::AFlamethrower()
{

}

void AFlamethrower::StartUse_Implementation()
{

}

void AFlamethrower::Use_Implementation()
{
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

void AFlamethrower::StopUse_Implementation()
{
	for (IBurnable* OldBurnable : OldBurnTarget) {
		OldBurnable->GetBurnComponent()->StopBurn(Interactor);
	} 

	OldBurnTarget.Empty();
	CurrentBurnTarget.Empty();
}

