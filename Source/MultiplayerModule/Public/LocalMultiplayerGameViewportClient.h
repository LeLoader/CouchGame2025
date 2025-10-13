#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "LocalMultiplayerGameViewportClient.generated.h"

class ULocalMultiplayerSubsystem;

UCLASS()
class MULTIPLAYERMODULE_API ULocalMultiplayerGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:
	virtual void PostInitProperties() override;

	virtual bool InputKey(const FInputKeyEventArgs& EventArgs) override;

	virtual bool InputAxis(FViewport* InViewport, FInputDeviceId InputDevice, FKey Key, float Delta, float DeltaTime,
						   int32 NumSamples = 1, bool bGamepad = false) override;
};