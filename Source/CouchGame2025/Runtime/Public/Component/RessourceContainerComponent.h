#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Delegates/Delegate.h"

#include "RessourceContainerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRessourceUpdatedSignature, float, NewRessourceAmount, float, OldRessourceAmount);

DECLARE_MULTICAST_DELEGATE(FOnContainerEmptySignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContainerEmptySignatureBP);
DECLARE_MULTICAST_DELEGATE(FOnContainerFullSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContainerFullSignatureBP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRessourceStartMovingSignatureBP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRessourceStopMovingSignatureBP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRessourceMoveInstantSignatureBP);

UENUM(BlueprintType)
enum class FRessourceType : uint8 {
	WATER = 0 UMETA(DisplayName = "Water"),
	ICE = 1 UMETA(DisplayName = "Ice"),
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COUCHGAME2025_API URessourceContainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URessourceContainerComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FRessourceType RessourceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxRessourceAmount = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentRessourceAmount = 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<URessourceContainerComponent*> TargetContainers;

public:
	UFUNCTION(BlueprintCallable)
	float AddRessource(float Amount);

	UFUNCTION(BlueprintCallable)
	float RemoveRessource(float Amount);

	UFUNCTION(BlueprintCallable)
	float InstantMoveRessource(float DeltaTime, URessourceContainerComponent* Target);

	UFUNCTION(BlueprintCallable)
	void StartMovingRessource(URessourceContainerComponent* Target);

	UFUNCTION(BlueprintCallable)
	void StopMovingRessource(URessourceContainerComponent* Target);

	UPROPERTY(BlueprintAssignable)
	FOnRessourceUpdatedSignature OnRessourceUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnContainerEmptySignatureBP OnContainerEmptyBP;
	FOnContainerEmptySignature OnContainerEmpty;

	UPROPERTY(BlueprintAssignable)
	FOnContainerFullSignatureBP OnContainerFullBP;
	FOnContainerFullSignature OnContainerFull;

	UPROPERTY(BlueprintAssignable)
	FOnRessourceStartMovingSignatureBP OnRessourceStartMovingBP;

	UPROPERTY(BlueprintAssignable)
	FOnRessourceStopMovingSignatureBP OnRessourceStopMovingBP;

	UPROPERTY(BlueprintAssignable)
	FOnRessourceMoveInstantSignatureBP OnRessourceMoveInstantBP;

#pragma region Getter/Setter

	UFUNCTION(BlueprintGetter)
	bool IsContainerFull() const { return FMath::Abs(CurrentRessourceAmount - MaxRessourceAmount) < UE_KINDA_SMALL_NUMBER; }

	UFUNCTION(BlueprintGetter)
	bool IsContainerEmpty() const { return CurrentRessourceAmount < UE_KINDA_SMALL_NUMBER; }

	UFUNCTION(BlueprintGetter)
	float GetMaxRessourceAmount() const { return MaxRessourceAmount; }
	
	UFUNCTION(BlueprintGetter)
	float GetCurrentRessourceAmount() const { return CurrentRessourceAmount; }

	UFUNCTION(BlueprintSetter)
	void SetRessourceType(FRessourceType NewRessourceType) { RessourceType = NewRessourceType; }

#pragma endregion Getter/Setter
};
