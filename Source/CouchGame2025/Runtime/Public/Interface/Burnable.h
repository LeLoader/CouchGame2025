

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Burnable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBurnable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COUCHGAME2025_API IBurnable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual void Burn() = 0;
};
