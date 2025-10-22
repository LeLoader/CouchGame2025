#pragma once

#include "CoreMinimal.h"
#include "LocalMultiplayerSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LocalMultiplayerSubsystem.generated.h"

UCLASS()
class MULTIPLAYERMODULE_API ULocalMultiplayerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void Initialize(FSubsystemCollectionBase& Collection) override;
	
	UFUNCTION(BlueprintCallable)
	void CreateAndInitPlayers(ELocalMultiplayerInputMappingType MappingType);
	
	int GetAssignedPlayerIndexFromKeyboardProfileIndex(int KeyboardProfileIndex);
	
	int AssignNewPlayerToKeyboardProfile(int KeyboardProfileIndex);
	
	void AssignKeyboardMapping(int PlayerIndex, int KeyboardProfileIndex, ELocalMultiplayerInputMappingType MappingType) const;
	
	int GetAssignedPlayerIndexFromGamepadDeviceID(int DeviceID);
	
	int AssignNewPlayerToGamepadDeviceID(int DeviceID);
	
	void AssignGamepadInputMapping(int PlayerIndex, ELocalMultiplayerInputMappingType MappingType) const;

protected:
	UPROPERTY()
	uint8 LastAssignedPlayerIndex = -1;

	UPROPERTY()
	TMap<int, int> PlayerIndexFromKeyboardProfileIndex;

	UPROPERTY()
	TMap<int, int> PlayerIndexFromGamepadProfileIndex;

	UPROPERTY(BlueprintReadOnly)
	const ULocalMultiplayerSettings* LocalMultiplayerSettings;
};