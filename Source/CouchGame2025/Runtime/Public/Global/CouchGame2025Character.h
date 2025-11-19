// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "../Component/RessourceContainerComponent.h"
#include "CouchGame2025Character.generated.h"

class UPickupComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ACouchGame2025Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneComponent* CameraBoomRoot;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
#pragma region Inputs

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;

	/** Use Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* UseAction;

	/** Rope Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RopeAction;

#pragma endregion Inputs

public:
	ACouchGame2025Character();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "bHidePickupComponent", EditConditionHides))
	UPickupComponent* PickupComponent;

	UPROPERTY(EditDefaultsOnly)
	bool bHidePickupComponent;

protected:

	/** Called for movement */
	void Move(const FInputActionValue& Value);

	/** Called for looking */
	void Look(const FInputActionValue& Value);
	
	/** Called for interacting */
	void Interact(const FInputActionValue& Value);

#pragma region Rope

	/** Called to toggle rope*/
	void ToggleRopeMode(const FInputActionValue& Value);

	/**  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsConnectedToARope;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsRopeFree;

#pragma endregion Rope
			

protected:

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

#pragma region Water

public:
	UPROPERTY(VisibleAnywhere)
	URessourceContainerComponent* WaterTank;

#pragma endregion Water

#pragma region Grab

public:	
	UFUNCTION()
	void MoveWhenGrabbing(FVector2D Movement);

	UPROPERTY()
	FVector2D InputMovement;

	UPROPERTY(VisibleAnywhere)
	bool bIsGrabbing;

private:

	UFUNCTION()
	void StopMove();
	
#pragma endregion Grab	
};

