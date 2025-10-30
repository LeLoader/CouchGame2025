#pragma once

#include "LocalMultiplayerSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"

void ULocalMultiplayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	LocalMultiplayerSettings = GetDefault<ULocalMultiplayerSettings>();
}

void ULocalMultiplayerSubsystem::CreateAndInitPlayers(ELocalMultiplayerInputMappingType MappingType)
{
	for (int i = 0; i < LocalMultiplayerSettings->GetNbKeyboardProfiles(); i++)
	{
		UGameplayStatics::CreatePlayer(GetWorld(), i, true);
	}
	for (int i = 0; i < LocalMultiplayerSettings->NbMaxGamepads; i++)
	{
		UGameplayStatics::CreatePlayer(GetWorld(), i + LocalMultiplayerSettings->GetNbKeyboardProfiles());
	}
}

int ULocalMultiplayerSubsystem::GetAssignedPlayerIndexFromKeyboardProfileIndex(int KeyboardProfileIndex)
{
	if (PlayerIndexFromKeyboardProfileIndex.Contains(KeyboardProfileIndex))
	{
		return *PlayerIndexFromKeyboardProfileIndex.Find(KeyboardProfileIndex);
	}
	return -1;
}

int ULocalMultiplayerSubsystem::AssignNewPlayerToKeyboardProfile(int KeyboardProfileIndex)
{
	LastAssignedPlayerIndex++;
	PlayerIndexFromKeyboardProfileIndex.Add(KeyboardProfileIndex, LastAssignedPlayerIndex);
	return LastAssignedPlayerIndex;
}

void ULocalMultiplayerSubsystem::AssignKeyboardMapping(int PlayerIndex, int KeyboardProfileIndex, ELocalMultiplayerInputMappingType MappingType) const
{
	UInputMappingContext* InputMappingcontext = LocalMultiplayerSettings->KeyboardProfileData[KeyboardProfileIndex].GetIMCFromType(MappingType);
	APlayerController* Controller = UGameplayStatics::GetPlayerControllerFromID(GetWorld(), PlayerIndex);
	if (Controller == nullptr) return;
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Controller->GetLocalPlayer());
	if (Subsystem == nullptr) return;
	FModifyContextOptions Options = FModifyContextOptions();
	Options.bIgnoreAllPressedKeysUntilRelease = false;
	Subsystem->AddMappingContext(InputMappingcontext, -1, Options);
}

int ULocalMultiplayerSubsystem::GetAssignedPlayerIndexFromGamepadDeviceID(int DeviceID)
{
	if (PlayerIndexFromGamepadProfileIndex.Contains(DeviceID))
	{
		return *PlayerIndexFromGamepadProfileIndex.Find(DeviceID);
	}
	return -1;
}

int ULocalMultiplayerSubsystem::AssignNewPlayerToGamepadDeviceID(int deviceID)
{
	LastAssignedPlayerIndex++;
	PlayerIndexFromGamepadProfileIndex.Add(deviceID, LastAssignedPlayerIndex);
	return LastAssignedPlayerIndex;
}

void ULocalMultiplayerSubsystem::AssignGamepadInputMapping(int PlayerIndex, ELocalMultiplayerInputMappingType MappingType) const
{
	UInputMappingContext* InputMappingcontext = LocalMultiplayerSettings->GamepadProfileData.GetIMCFromType(MappingType);
	APlayerController* Controller = UGameplayStatics::GetPlayerControllerFromID(GetWorld(), PlayerIndex);
	if (Controller == nullptr) return;
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Controller->GetLocalPlayer());
	if (Subsystem == nullptr) return;
	FModifyContextOptions Options = FModifyContextOptions();
	Options.bIgnoreAllPressedKeysUntilRelease = false;
	Subsystem->AddMappingContext(InputMappingcontext, -1, Options);
}

void ULocalMultiplayerSubsystem::SetCurrentMappingType(ELocalMultiplayerInputMappingType InMappingType)
{
	CurrentMappingType = InMappingType;
}

void ULocalMultiplayerSubsystem::ResetPlayers()
{
	PlayerIndexFromKeyboardProfileIndex.Empty();
	PlayerIndexFromGamepadProfileIndex.Empty();
	LastAssignedPlayerIndex = -1;
}