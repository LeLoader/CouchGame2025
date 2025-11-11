

#pragma once

#include "CoreMinimal.h"
#include "PickUpObject.h"
#include "CouchGame2025/Runtime/Public/Interface/Usable.h"
#include "Flamethrower.generated.h"

class IBurnable;

/**
 * 
 */
UCLASS(Blueprintable)
class COUCHGAME2025_API AFlamethrower : public APickUpObject, public IUsable
{
	GENERATED_BODY()

public:
	AFlamethrower();

	UFUNCTION(BlueprintNativeEvent)
	void StartUse() override;

	UFUNCTION(BlueprintNativeEvent)
	void Use() override;

	UFUNCTION(BlueprintNativeEvent)
	void StopUse() override;

	UPROPERTY(EditAnywhere)
	float FlamethrowerLength = 250.f;

	UPROPERTY(EditAnywhere)
	float FlamethrowerWidth = 32.f;

protected:
	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<IBurnable*> CurrentBurnTarget;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<IBurnable*> OldBurnTarget;
};
