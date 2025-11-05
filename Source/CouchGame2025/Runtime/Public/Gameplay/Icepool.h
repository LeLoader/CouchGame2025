

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CouchGame2025/Runtime/Public/Interface/Burnable.h"
#include "Icepool.generated.h"

UCLASS(Blueprintable)
class COUCHGAME2025_API AIcepool : public AActor, public IBurnable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIcepool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void Burn() override;
	
};
