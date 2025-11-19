#include "CouchGame2025/Runtime/Public/Gameplay/TransferPoint.h"

ATransferPoint::ATransferPoint()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATransferPoint::BeginPlay()
{
	Super::BeginPlay();

}

void ATransferPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

