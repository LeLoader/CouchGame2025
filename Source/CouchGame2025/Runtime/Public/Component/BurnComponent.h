

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BurnComponent.generated.h"

class IBurnable;

#pragma once

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBurnStarted);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class COUCHGAME2025_API UBurnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBurnComponent();

	UFUNCTION()
	void StartBurn(ACouchGame2025Character* Instigator);

	UFUNCTION()
	void StopBurn(ACouchGame2025Character* Instigator);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int NumOfSourceToBurn = 1;

	UFUNCTION(BlueprintCallable, CallInEditor)
	void AddFakeBurnSource();

	UFUNCTION(BlueprintCallable, CallInEditor)
	void RemoveFakeBurnSource();
	
	UPROPERTY(BlueprintAssignable, Category = "Burn") 
	FOnBurnStarted OnBurnStarted;

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	// UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	IBurnable* Owner;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<ACouchGame2025Character*> BurnInstigators;
	
};
