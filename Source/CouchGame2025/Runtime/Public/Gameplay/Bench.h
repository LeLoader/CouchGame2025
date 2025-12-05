

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/Interactable.h"
#include "Engine/StaticMeshActor.h"

#include "Bench.generated.h"

UCLASS()
class COUCHGAME2025_API ABench : public AStaticMeshActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	ABench();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneComponent* Seat1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneComponent* Seat2;

	UPROPERTY(VisibleAnywhere)
	ACouchGame2025Character* Seat1UsedBy = nullptr;

	UPROPERTY(VisibleAnywhere)
	ACouchGame2025Character* Seat2UsedBy = nullptr;
	
public:
	bool Interact(ACouchGame2025Character* A) override;

	int GetPriority() override;

};
