

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CouchGame2025/Runtime/Public/Interface/Burnable.h"

#include "Icepool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnElementUpdatedSignature, float, IceAmount, float, WaterAmount);

class UBoxComponent;

UCLASS(Blueprintable)
class COUCHGAME2025_API AIcepool : public AActor, public IBurnable
{
	GENERATED_BODY()

protected:
	AIcepool();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UBoxComponent* WaterTriggerBox;

	UFUNCTION()
	void OnWaterBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:
	UFUNCTION(BlueprintCallable)
	virtual void Burn() override;

	UPROPERTY(BlueprintAssignable)
	FOnElementUpdatedSignature OnElementUpdated;

protected:
	void StartGatherWater();

	UFUNCTION(BlueprintCallable, Category = "Icepool")
	float GatherWater(float MaxGatheredWater);

	void ElementUpdated();

	UPROPERTY(VisibleAnywhere, Category = "Icepool")
	float IceAmount = 1;

	UPROPERTY(VisibleAnywhere, Category = "Icepool")
	float WaterAmount = 0;
};
