

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CouchGame2025/Runtime/Public/Interface/Burnable.h"

#include "Icepool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnElementUpdatedSignature, float, IceAmount, float, WaterAmount);

class UBoxComponent;
class ACouchGame2025Character;

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

	UFUNCTION()
	void OnWaterBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


public:
	UFUNCTION(BlueprintCallable)
	virtual void Burn() override;

	UPROPERTY(BlueprintAssignable)
	FOnElementUpdatedSignature OnElementUpdated;

protected:
	void GatherWaterForCharacter(ACouchGame2025Character* Character);
	float GatherWater(float MaxGatheredWater);
	void ElementUpdated();

	UPROPERTY(EditDefaultsOnly, Category = "Icepool", meta = (Units = "kg"))
	float IceStartAmount = 1;

	UPROPERTY(VisibleAnywhere, Category = "Icepool", meta = (Units = "kg"))
	float IceAmount;

	UPROPERTY(EditDefaultsOnly, Category = "Icepool", meta = (Units = "x"))
	float IceToWaterRatio = 1;

	UPROPERTY(VisibleAnywhere, Category = "Icepool", meta = (Units = "kg"))
	float WaterAmount;

	TArray<ACouchGame2025Character*> GatheringCharacters;
};
