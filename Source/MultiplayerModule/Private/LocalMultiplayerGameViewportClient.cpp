#include "LocalMultiplayerGameViewportClient.h"
#include "LocalMultiplayerSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "EnhancedInputSubsystems.h"


void ULocalMultiplayerGameViewportClient::PostInitProperties()
{
	Super::PostInitProperties();
	MaxSplitscreenPlayers = 8;
}

bool ULocalMultiplayerGameViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	const ULocalMultiplayerSettings* settings = GetDefault<ULocalMultiplayerSettings>();
	if (GameInstance == nullptr)
	{
		return Super::InputKey(EventArgs);
	}
	ULocalMultiplayerSubsystem* Subsystem = GameInstance->GetSubsystem<ULocalMultiplayerSubsystem>();
	if (!EventArgs.Key.IsGamepadKey())
	{
		int KeyboardProfile = settings->FindKeyboardProfileIndexFromKey(EventArgs.Key, Subsystem->CurrentMappingType);
		if (KeyboardProfile == -1)
		{
			return Super::InputKey(EventArgs);
		}
		int PlayerIndex = Subsystem->GetAssignedPlayerIndexFromKeyboardProfileIndex(KeyboardProfile);
		if (PlayerIndex == -1)
		{
			//PlayerIndex = Subsystem->AssignNewPlayerToKeyboardProfile(KeyboardProfile);
			//Subsystem->AssignKeyboardMapping(PlayerIndex, KeyboardProfile, Subsystem->CurrentMappingType);
		}
		APlayerController* Controller = UGameplayStatics::GetPlayerControllerFromID(GetWorld(), PlayerIndex);
		if (Controller == nullptr)
		{
			return Super::InputKey(EventArgs);
		}
		FInputKeyParams params = FInputKeyParams(EventArgs.Key, EventArgs.Event, EventArgs.AmountDepressed);
		Controller->InputKey(params);
		return true;
		
	}
	else
	{
		int PlayerIndex = Subsystem->GetAssignedPlayerIndexFromGamepadDeviceID(EventArgs.InputDevice.GetId());
		if (PlayerIndex == -1)
		{
			//PlayerIndex = Subsystem->AssignNewPlayerToGamepadDeviceID(EventArgs.InputDevice.GetId());
			//Subsystem->AssignGamepadInputMapping(PlayerIndex, Subsystem->CurrentMappingType);
		}
		APlayerController* Controller = UGameplayStatics::GetPlayerControllerFromID(GetWorld(), PlayerIndex);
		if (Controller == nullptr)
		{
			return Super::InputKey(EventArgs);
		}
		FInputKeyParams params = FInputKeyParams(EventArgs.Key, EventArgs.Event, EventArgs.AmountDepressed);
		Controller->InputKey(params);
		return true;
	}
}

bool ULocalMultiplayerGameViewportClient::InputAxis(FViewport* InViewport, FInputDeviceId InputDevice, FKey Key, float Delta, float DeltaTime, int32 NumSamples, bool bGamepad)
{
	const ULocalMultiplayerSettings* settings = GetDefault<ULocalMultiplayerSettings>();
	if (GameInstance == nullptr)
	{
		return Super::InputAxis(InViewport, InputDevice, Key, Delta, DeltaTime, NumSamples, bGamepad);
	}
	ULocalMultiplayerSubsystem* Subsystem = GameInstance->GetSubsystem<ULocalMultiplayerSubsystem>();
	if (!Key.IsGamepadKey())
	{
		int KeyboardProfile = settings->FindKeyboardProfileIndexFromKey(Key, Subsystem->CurrentMappingType);
		if (KeyboardProfile == -1)
		{
			return Super::InputAxis(InViewport, InputDevice, Key, Delta, DeltaTime, NumSamples, bGamepad);
		}
		int PlayerIndex = Subsystem->GetAssignedPlayerIndexFromKeyboardProfileIndex(KeyboardProfile);
		if (PlayerIndex == -1)
		{
			// PlayerIndex = Subsystem->AssignNewPlayerToKeyboardProfile(KeyboardProfile);
			// Subsystem->AssignKeyboardMapping(PlayerIndex, KeyboardProfile, Subsystem->CurrentMappingType);
		}
		APlayerController* Controller = UGameplayStatics::GetPlayerControllerFromID(GetWorld(), PlayerIndex);
		if (Controller == nullptr)
		{
			return Super::InputAxis(InViewport, InputDevice, Key, Delta, DeltaTime, NumSamples, bGamepad);
		}
		Controller->InputAxis(Key, Delta, DeltaTime, NumSamples, bGamepad);
		return true;

	}
	else
	{
		int PlayerIndex = Subsystem->GetAssignedPlayerIndexFromGamepadDeviceID(InputDevice.GetId());
		if (PlayerIndex == -1)
		{
			// PlayerIndex = Subsystem->AssignNewPlayerToGamepadDeviceID(InputDevice.GetId());
			// Subsystem->AssignGamepadInputMapping(PlayerIndex, Subsystem->CurrentMappingType);
		}
		APlayerController* Controller = UGameplayStatics::GetPlayerControllerFromID(GetWorld(), PlayerIndex);
		if (Controller == nullptr)
		{
			return Super::InputAxis(InViewport, InputDevice, Key, Delta, DeltaTime, NumSamples, bGamepad);
		}
		Controller->InputAxis(Key, Delta, DeltaTime, NumSamples, bGamepad);
		return true;
	}
	
}