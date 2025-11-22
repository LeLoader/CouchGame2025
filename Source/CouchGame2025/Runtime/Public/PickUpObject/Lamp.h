

#pragma once

#include "CoreMinimal.h"
#include "PickUpObject.h"
#include "CouchGame2025/Runtime/Public/Interface/Usable.h"
#include "Lamp.generated.h"

class IBurnable;

/**
 * 
 */
UCLASS(Blueprintable)
class COUCHGAME2025_API ALamp : public APickUpObject, public IUsable
{
	GENERATED_BODY()

public:
	ALamp();
	void Tick(float DeltaTime) override;
	virtual void StartPickUp(ACouchGame2025Character* Player);
	virtual void StopPickUp(ACouchGame2025Character* Player);

	void StartUse() override;
	void Use() override;
	void StopUse() override;

	UFUNCTION(BlueprintNativeEvent)
	void EnableLamp();
	UFUNCTION(BlueprintNativeEvent)
	void DisableLamp();


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float FlamethrowerLength = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float FlamethrowerWidth = 32.f;

protected:
	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<IBurnable*> CurrentBurnTarget;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<IBurnable*> OldBurnTarget;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	bool bIsActive = false;

};
