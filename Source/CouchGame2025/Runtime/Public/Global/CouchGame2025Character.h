// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Interactable.h"
#include "GameFramework/Character.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Logging/LogMacros.h"
#include "Component/RessourceContainerComponent.h"
#include "CouchGame2025Character.generated.h"

class UPickupComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class ACouchCameraActor;
class USplineComponent;
class UTransfertSettings;
struct FInputActionValue;
class UCableComponentBis;
class UPhysicsConstraintComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class COUCHGAME2025_API ACouchGame2025Character : public ACharacter, public IInteractable
{
private:
	GENERATED_BODY()

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	// /** Camera boom positioning the camera behind the character */
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	// USceneComponent* CameraBoomRoot;
	// 
	// /** Camera boom positioning the camera behind the character */
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	// USpringArmComponent* CameraBoom;
	// 
	// /** Follow camera */
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	// UCameraComponent* FollowCamera;
	
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

	/** Transfert Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* TransfertAction;

#pragma endregion Inputs

public:
	ACouchGame2025Character();

	/** Pickup Component **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UPickupComponent* PickupComponent;

	UPROPERTY(EditDefaultsOnly)
	bool bHidePickupComponent;

	UPROPERTY()
	FVector RespawnPoint;

	UFUNCTION()
	void SetRespawnLocation(FVector InLocation);

#pragma region Transfert

	UFUNCTION(BlueprintImplementableEvent)
	void MoveAlongSpline(USplineComponent* Spline, bool IsMovingForward);

	UFUNCTION()
	void SetGameplayCameraAsCamera(float TimeToBlend);

	UFUNCTION()
	void SetSpecialCameraAsCamera(float TimeToBlend, AActor* InActor);


	DECLARE_MULTICAST_DELEGATE(FOnEndMovingAlongSpline);

	FOnEndMovingAlongSpline OnEndMovingAlongSpline;

	UFUNCTION(BlueprintCallable)
	void CallEventEndMovingAlongSpline();

	UFUNCTION()
	void InvertCamera();

	UFUNCTION()
	void Wait();

	UFUNCTION()
	void StopWait();
#pragma endregion

	int GetPriority() override;


	bool CanBeInteractWithSomethingInHand() override;

protected:

	/** Called for movement */
	void Move(const FInputActionValue& Value);

	/** Called for looking */
	void Look(const FInputActionValue& Value);
	
	/** Called for interacting */
	void Interact(const FInputActionValue& Value);

	/** Called for Transfering */
	void Transfert(const FInputActionValue& Value);

	void PolarToCartesian(float r, float theta, float phi, FVector& OutVector);
	void CartesianToPolar(FVector Vector, float& OutR, float& OutTheta, float& OutPhi);



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInverted;

	UPROPERTY()
	TObjectPtr<ACouchCameraActor> Camera;


#pragma region Rope

	/** Called to toggle rope*/
	void ToggleRopeMode(const FInputActionValue& Value);

#pragma endregion Rope
			

protected:

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// /** Returns CameraBoom subobject **/
	// FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	// /** Returns FollowCamera subobject **/
	// FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UPROPERTY(BlueprintReadWrite)
	bool bIsWaiting;

	UPROPERTY(BlueprintReadOnly)
	const UTransfertSettings* TransfertSettings;

	UFUNCTION()
	void ResetPlayer();

private:
	UFUNCTION(BlueprintCallable)
	void InvertCharacter();

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
	bool bIsGrabbedByAnotherPlayer;

	UPROPERTY(VisibleAnywhere)
	bool bIsGrabbing;

	UPROPERTY(VisibleAnywhere)
	bool bIsGrabbingPlayer;

	UPROPERTY(VisibleAnywhere)
	bool bIsAnyThrowTriggerToggled;

	UPROPERTY(VisibleAnywhere)
	bool bAreBothTriggerToggled;
	
	
	UFUNCTION()
	void GrabbedByOtherPlayer(ACouchGame2025Character* Other);

	// UFUNCTION()
	// void UpdateLeftTrigger();
	//
	// UPROPERTY()
	// bool bIsLeft
	//
	// UFUNCTION()
	// void UpdateRightTrigger();

	UFUNCTION()
	void ReleaseTrigger();
	
	UFUNCTION()
	void CheckForThrowPlayer();
	
	UFUNCTION()
	void ThrowPlayer();

	UFUNCTION()
	void StopThrow();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FrontLaunchForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float UpLaunchForce;
	
private:

	UFUNCTION()
	void StopMove();

	UPROPERTY(VisibleAnywhere)
	ACouchGame2025Character* OtherPlayer;

protected:
	virtual bool Interact(ACouchGame2025Character* A) override;
	
#pragma endregion Grab

private:
	UFUNCTION()
	void HandlePlanetaryJumped();
};

