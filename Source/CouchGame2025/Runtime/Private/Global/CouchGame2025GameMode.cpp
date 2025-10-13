// Copyright Epic Games, Inc. All Rights Reserved.

#include "CouchGame2025/Runtime/Public/Global/CouchGame2025GameMode.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "UObject/ConstructorHelpers.h"

ACouchGame2025GameMode::ACouchGame2025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
