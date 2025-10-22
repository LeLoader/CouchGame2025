// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CouchGame2025GameMode.generated.h"

UCLASS(minimalapi)
class ACouchGame2025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACouchGame2025GameMode();

	virtual void StartPlay() override;
};



