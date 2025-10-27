#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABlackHole.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class COUCHGAME2025_API AABlackHole : public AActor
{
	GENERATED_BODY()

public:
	AABlackHole();

protected:
	virtual void BeginPlay() override;

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