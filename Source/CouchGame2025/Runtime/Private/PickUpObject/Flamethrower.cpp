


#include "CouchGame2025/Runtime/Public/PickUpObject/Flamethrower.h"


AFlamethrower::AFlamethrower()
{

}

void AFlamethrower::StartUse_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, "StartUse()");
}

void AFlamethrower::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, "Use()");
}

void AFlamethrower::StopUse_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, "StopUse()");
}

