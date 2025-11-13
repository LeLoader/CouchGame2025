

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CouchGame2025/Runtime/Public/Interface/CameraFollowable.h"
#include "InterestPoint.generated.h"

class USphereComponent;

UCLASS()
class COUCHGAME2025_API AInterestPoint : public AActor, public ICameraFollowable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInterestPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> InfluenceZone;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInfluenceZoneEntered, AInterestPoint*, NewInterestPoint);

	UPROPERTY()
	FOnInfluenceZoneEntered OnInfluenceZoneEnteredEvent;

	virtual FVector GetFollowPosition() override;

private:
		UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	                    bool bFromSweep, const FHitResult& SweepResult);

	
	
};
