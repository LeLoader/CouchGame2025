


#include "CouchGame2025/Runtime/Public/PickUpObject/Flamethrower.h"

#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include <CouchGame2025/Runtime/Public/Interface/Burnable.h>

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
	
	for (FHitResult Hit : Hits) {
		if (IBurnable* Burnable = Cast<IBurnable>(Hit.GetActor())) {
			Burnable->Burn();
		}
	}
}

void AFlamethrower::StopUse_Implementation()
{

}

