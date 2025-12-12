

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CouchGame2025/Runtime/Public/Interface/Burnable.h"

#include "Icepool.generated.h"

class UBoxComponent;
class ACouchGame2025Character;
class URessourceContainerComponent;

UCLASS(Blueprintable)
class COUCHGAME2025_API AIcepool : public AActor, public IBurnable
{
	GENERATED_BODY()

protected:
	AIcepool();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UBoxComponent* WaterTriggerBox;

	UPROPERTY(EditAnywhere)
	UBurnComponent* BurnComponent;

	UFUNCTION()
	void OnWaterBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnWaterBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	URessourceContainerComponent* WaterContainer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	URessourceContainerComponent* IceContainer;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BP_OnIceMelt();

// Start of IBurnable implementation

public:
	UFUNCTION(BlueprintCallable)
	virtual void Burn(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	UBurnComponent* GetBurnComponent() override;

// End of IBurnable implementation

};
