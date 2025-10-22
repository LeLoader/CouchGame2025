#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "LocalMultiplayerSettings.generated.h"

class UInputMappingContext;

UENUM(BlueprintType)
enum class ELocalMultiplayerInputMappingType : uint8
{
	InGame,
	Menu
};


USTRUCT(BlueprintType)
struct FLocalMultiplayerProfileData
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ProfileName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> IMCInGame;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> IMCMenu;

	bool ContainsKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const;

	UInputMappingContext* GetIMCFromType(ELocalMultiplayerInputMappingType MappingType) const;
};

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Local Multiplayer Settings"), BlueprintType)
class MULTIPLAYERMODULE_API ULocalMultiplayerSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="LocalMultiplayer")
	TArray<FLocalMultiplayerProfileData> KeyboardProfileData;

	int GetNbKeyboardProfiles() const;

	UFUNCTION(BlueprintCallable, Category = "LocalMultiplayer")
	int FindKeyboardProfileIndexFromKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="LocalMultiplayer")
	FLocalMultiplayerProfileData GamepadProfileData;

	UPROPERTY(Config, EditAnywhere, Category = "LocalMultiplayer")
	int NbMaxGamepads = 4;

};