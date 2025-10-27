

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LocalMultiplayerGameInstance.generated.h"


UCLASS()
class MULTIPLAYERMODULE_API ULocalMultiplayerGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:	

	virtual ULocalPlayer* CreateInitialPlayer(FString& OutError) override;

	UFUNCTION()
	void CreateSecondPlayer(FString& OutError);
};
