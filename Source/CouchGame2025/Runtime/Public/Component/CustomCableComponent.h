

#pragma once

#include "CoreMinimal.h"
#include "CableComponent.h"
#include "CustomCableComponent.generated.h"

class USphereComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COUCHGAME2025_API UCustomCableComponent : public UCableComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCustomCableComponent();
	
	virtual void OnRegister() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(VisibleInstanceOnly)
	TArray<USphereComponent*> Collisions;

public:
	UPROPERTY(EditAnywhere)
	bool bShowCustomCollisions = true;

	UPROPERTY(EditAnywhere)
	float DebugSize = 5.f;

	UPROPERTY(EditAnywhere)
	bool bDoCustomCollision = false;
};
