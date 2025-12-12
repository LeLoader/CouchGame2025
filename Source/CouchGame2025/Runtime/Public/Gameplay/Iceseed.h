

#pragma once

#include "CoreMinimal.h"
#include "PickUpObject/PickUpObject.h"
#include "Interface/Burnable.h"

#include "Iceseed.generated.h"

class UBoxComponent;
class URessourceContainerComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIceSeedPickableSignature);


UCLASS()
class COUCHGAME2025_API AIceSeed : public APickUpObject, public IBurnable

{
	GENERATED_BODY()
	
public:	
	AIceSeed();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

#pragma region Components

	UPROPERTY(EditAnywhere)
	UBoxComponent* WaterTrigger;

	UPROPERTY(EditAnywhere)
	UBoxComponent* BurnTrigger;

	UPROPERTY(EditAnywhere)
	UBurnComponent* BurnComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<URessourceContainerComponent> IceContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<URessourceContainerComponent> WaterContainer;

#pragma endregion Components
	
public:
	void Burn(float DeltaTime) override;
	UBurnComponent* GetBurnComponent() override;

	UPROPERTY(BlueprintAssignable)
	FOnIceSeedPickableSignature OnIceSeedPickable;

	UFUNCTION()
	void OnWaterBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnWaterBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


private:
	UFUNCTION()
	void HandleMelting();

};
