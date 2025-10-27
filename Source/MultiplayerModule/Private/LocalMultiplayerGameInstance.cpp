


#include "LocalMultiplayerGameInstance.h"

ULocalPlayer* ULocalMultiplayerGameInstance::CreateInitialPlayer(FString& OutError)
{
	ULocalPlayer* LocalPlayer = Super::CreateInitialPlayer(OutError);

	FString OutError2;
	CreateSecondPlayer(OutError2);

	return LocalPlayer;
}

void ULocalMultiplayerGameInstance::CreateSecondPlayer(FString& OutError)
{
	CreateLocalPlayer(1, OutError, true);
}