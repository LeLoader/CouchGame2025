#pragma once

#include "CoreMinimal.h"
#include "LocalMultiplayerSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Delegates/Delegate.h"
#include "LocalMultiplayerSubsystem.generated.h"

enum class EHardwareDevicePrimaryType : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNewPlayerMappedSignature, int32, Index, EHardwareDevicePrimaryType, DeviceType);

UCLASS()
class MULTIPLAYERMODULE_API ULocalMultiplayerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnNewPlayerMappedSignature OnNewPlayerMapped;

	void Initialize(FSubsystemCollectionBase& Collection) override;
	
	UFUNCTION(BlueprintCallable)
	void CreateAndInitPlayers(ELocalMultiplayerInputMappingType MappingType);
	
	int GetAssignedPlayerIndexFromKeyboardProfileIndex(int KeyboardProfileIndex);
	
	int AssignNewPlayerToKeyboardProfile(int KeyboardProfileIndex);
	
	void AssignKeyboardMapping(int PlayerIndex, int KeyboardProfileIndex, ELocalMultiplayerInputMappingType MappingType) const;
	
	int GetAssignedPlayerIndexFromGamepadDeviceID(int DeviceID);
	
	int AssignNewPlayerToGamepadDeviceID(int DeviceID);
	
	void AssignGamepadInputMapping(int PlayerIndex, ELocalMultiplayerInputMappingType MappingType) const;

	UFUNCTION(BlueprintCallable)
	void SetCurrentMappingType(ELocalMultiplayerInputMappingType InMappingType);

	UPROPERTY(BlueprintReadOnly)
	ELocalMultiplayerInputMappingType CurrentMappingType;

protected:

	UPROPERTY(BlueprintReadOnly)
	uint8 LastAssignedPlayerIndex = -1;

	UPROPERTY()
	TMap<int, int> PlayerIndexFromKeyboardProfileIndex;

	UPROPERTY()
	TMap<int, int> PlayerIndexFromGamepadProfileIndex;

	UPROPERTY(BlueprintReadOnly)
	const ULocalMultiplayerSettings* LocalMultiplayerSettings;

	UFUNCTION(BlueprintCallable)
	void ResetPlayers();

};