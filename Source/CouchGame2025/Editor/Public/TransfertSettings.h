

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "TransfertSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Transfert Settings"), BlueprintType)
class COUCHGAME2025_API UTranfertSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int CharacterTransfertTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EViewTargetBlendFunction> CameraBlendType;
	
};
