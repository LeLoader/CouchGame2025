

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "CameraFollowable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCameraFollowable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COUCHGAME2025_API ICameraFollowable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FVector GetFollowPosition() = 0;
	
};
