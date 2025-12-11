#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/Delegate.h"

#include "ABlackHole.generated.h"

class USphereComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTrashDestroyedSignature, AActor*, Trash);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDiedFromBlackHoleSignature, ACouchGame2025Character*, Player);

UCLASS()
class COUCHGAME2025_API AABlackHole : public AActor
{
	GENERATED_BODY()

public:
	AABlackHole();

	UPROPERTY(BlueprintAssignable)
	FOnTrashDestroyedSignature OnTrashDestroyed;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerDiedFromBlackHoleSignature OnPlayerDiedFromBlackHole;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BP_OnCharaRespawn();	


private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* BlackHoleMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* CollisionSphere;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	                    bool bFromSweep, const FHitResult& SweepResult);
};