// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CouchGame2025/Runtime/Public/Interface/Interactable.h"
#include "GameFramework/Character.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Logging/LogMacros.h"
#include "Component/RessourceContainerComponent.h"
#include "Interface/CameraFollowable.h"
#include "CouchGame2025Character.generated.h"

class UPickupComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ACouchGame2025Character : public ACharacter, public ICameraFollowable, public IInteractable
{
private:
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Scene component for relative rotation of camera*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent;

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

	/** Throw Left Trigger Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ThrowLeftAction;

	/** Throw Right Trigger Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ThrowRightAction;

	/** Rope Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RopeAction;

	/** Bridge Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* BridgeAction;

#pragma endregion Inputs

public:
	ACouchGame2025Character();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "bHidePickupComponent", EditConditionHides))
	UPickupComponent* PickupComponent;

	UPROPERTY(EditDefaultsOnly)
	bool bHidePickupComponent;
	/** Pickup Component **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UPickupComponent* PickupComponent;

	/** Projectile Movement Component **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UProjectileMovementComponent* ProjectileMovement;

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/** Called for movement */
	void Move(const FInputActionValue& Value);

	/** Called for looking */
	void Look(const FInputActionValue& Value);
	
	/** Called for interacting */
	void Interact(const FInputActionValue& Value);

	void PolarToCartesian(float r, float theta, float phi, FVector& OutVector);
	void CartesianToPolar(FVector Vector, float& OutR, float& OutTheta, float& OutPhi);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInverted;

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

	virtual FVector GetFollowPosition() override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

#pragma region Water

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
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

	UPROPERTY(VisibleAnywhere)
	bool bIsGrabbingPlayer;
	
	UFUNCTION()
	void GrabbedByOtherPlayer(ACouchGame2025Character* Other);

	UFUNCTION()
	void ThrowPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float frontLaunchForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float UpLaunchForce;
	
private:

	UFUNCTION()
	void StopMove();

	UPROPERTY(VisibleAnywhere)
	ACouchGame2025Character* OtherPlayer;

protected:
	virtual void Interact(ACouchGame2025Character* A) override;
	
#pragma endregion Grab	
};

