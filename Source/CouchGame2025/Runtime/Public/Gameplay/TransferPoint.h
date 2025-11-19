#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TransferPoint.generated.h"

UCLASS()
class COUCHGAME2025_API ATransferPoint : public AActor
{
	GENERATED_BODY()

public:
	ATransferPoint();

	UPROPERTY(EditAnywhere)
	AActor *Bp_Planet;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
