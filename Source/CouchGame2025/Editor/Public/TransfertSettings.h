

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "TransfertSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Transfert Settings"), BlueprintType)
class COUCHGAME2025_API UTransfertSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly)
	int CharacterTransfertTime;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EViewTargetBlendFunction> CameraBlendType;
	
};
