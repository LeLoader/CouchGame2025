// Language: cpp
// File: `Source/CouchGame2025/Runtime/Public/Component/PlanetaryMovementComponent.h`

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlanetaryMovementComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlanetaryJumped);

UCLASS()
class COUCHGAME2025_API UPlanetaryMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UPlanetaryMovementComponent();

	UFUNCTION(BlueprintCallable)
	void UpdateGravityDirection(const FVector& NewGravityDirection);

	UFUNCTION(BlueprintCallable)
	void InvertGravity();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseExternalGravityDirection = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
	FVector PlanetCenter = FVector::ZeroVector;

	virtual bool DoJump(bool bReplayingMoves) override;

	UPROPERTY(BlueprintAssignable, Category = "Planetary")
	FOnPlanetaryJumped OnPlanetaryJumped;

protected:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	APawn* CachedOwnerPawn = nullptr;
};