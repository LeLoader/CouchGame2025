


#include "LocalMultiplayerGameInstance.h"

void ULocalMultiplayerGameInstance::CreateLocalPlayerWithDevice(int32 ControllerId, FString& OutError, bool bSpawnPlayerController)
{
	ULocalPlayer* Player = CreateLocalPlayer(ControllerId, OutError, bSpawnPlayerController);
}

void ULocalMultiplayerGameInstance::HandleInputDeviceConnectionChange(EInputDeviceConnectionState NewConnectionState, FPlatformUserId PlatformUserId, FInputDeviceId InputDeviceId)
{
	Super::HandleInputDeviceConnectionChange(NewConnectionState, PlatformUserId, InputDeviceId);
}