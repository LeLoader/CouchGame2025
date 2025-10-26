

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LocalMultiplayerGameInstance.generated.h"


UCLASS()
class MULTIPLAYERMODULE_API ULocalMultiplayerGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable)
	void CreateLocalPlayerWithDevice(int32 ControllerId, FString& OutError, bool bSpawnPlayerController);

	void HandleInputDeviceConnectionChange(EInputDeviceConnectionState NewConnectionState, FPlatformUserId PlatformUserId, FInputDeviceId InputDeviceId) override;
};
