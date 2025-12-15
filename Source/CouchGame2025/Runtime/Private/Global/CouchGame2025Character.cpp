// Copyright Epic Games, Inc. All Rights Reserved.

#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include <CouchGame2025/Runtime/Public/Interface/Interactable.h>

#include "CouchGame2025/Runtime/Public/Component/PickupComponent.h"
#include "ProfilingDebugging/CookStats.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "CouchGame2025/Runtime/Public/Component/PickupComponent.h"
#include "CouchGame2025/Runtime/Public/Gameplay/CouchCameraActor.h"
#include "CouchGame2025/Runtime/Public/Component/PlanetaryMovementComponent.h"
#include "CouchGame2025/Editor/Public/TransfertSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "ProfilingDebugging/CookStats.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"
#include "CableComponentBis/Source/CableComponentBis/Classes/CableComponentBis.h"

#define ECC_Interactable ECC_GameTraceChannel2


DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ACouchGame2025Character
ACouchGame2025Character::ACouchGame2025Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bIsGrabbing = false;
	bIsGrabbingPlayer = false;
	bIsAnyThrowTriggerToggled = false;
	bAreBothTriggerToggled = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// // Create a camera boom (pulls in towards the player if there is a collision)
	// CameraBoomRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CameraBoomRoot"));
	// CameraBoomRoot->SetupAttachment(RootComponent);
	// 
	// // Create a camera boom (pulls in towards the player if there is a collision)
	// CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// CameraBoom->SetupAttachment(CameraBoomRoot);
	// CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	// CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	// 
	// // Create a follow camera
	// FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	// FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	PickupComponent = CreateDefaultSubobject<UPickupComponent>(TEXT("PickupComponent"));
	PickupComponent->SetupAttachment(GetCapsuleComponent());

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	WaterTank = CreateDefaultSubobject<URessourceContainerComponent>(TEXT("WaterTank"));
	WaterTank->SetRessourceType(FRessourceType::WATER);
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACouchGame2025Character::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ACouchGame2025Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACouchGame2025Character::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ACouchGame2025Character::StopMove);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACouchGame2025Character::Look);

		// Pickup & release
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, PickupComponent, &UPickupComponent::TryPickUp);
		//EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, PickupComponent, &UPickupComponent::HandleInputCompleted, this);

		// Use (Move everything in a specific imc that's added on pickup
		EnhancedInputComponent->BindAction(UseAction, ETriggerEvent::Started, PickupComponent, &UPickupComponent::StartUse);
		EnhancedInputComponent->BindAction(UseAction, ETriggerEvent::Triggered, PickupComponent, &UPickupComponent::Use);
		EnhancedInputComponent->BindAction(UseAction, ETriggerEvent::Completed, PickupComponent, &UPickupComponent::StopUse);

		// Rope
		EnhancedInputComponent->BindAction(RopeAction, ETriggerEvent::Started, this, &ACouchGame2025Character::ToggleRopeMode);

		//Transfert
		EnhancedInputComponent->BindAction(TransfertAction, ETriggerEvent::Started, this, &ACouchGame2025Character::Transfert);

		// Bridge
		//EnhancedInputComponent->BindAction(BridgeAction, ETriggerEvent::Started, this, &AABridge::ToggleBridge);
		// Throw Player
		EnhancedInputComponent->BindAction(ThrowLeftAction, ETriggerEvent::Started, this, &ACouchGame2025Character::CheckForThrowPlayer);
		EnhancedInputComponent->BindAction(ThrowRightAction, ETriggerEvent::Started, this, &ACouchGame2025Character::CheckForThrowPlayer);
		EnhancedInputComponent->BindAction(ThrowLeftAction, ETriggerEvent::Completed, this, &ACouchGame2025Character::ReleaseTrigger);
		EnhancedInputComponent->BindAction(ThrowRightAction, ETriggerEvent::Completed, this, &ACouchGame2025Character::ReleaseTrigger);
	
		//Look at Player
		EnhancedInputComponent->BindAction(LookAtPLayerAction, ETriggerEvent::Started, this, &ACouchGame2025Character::LookAtPlayer);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ACouchGame2025Character::PolarToCartesian(float r, float theta, float phi, FVector& OutVector)
{
	OutVector.X = r * FMath::Sin(theta) * FMath::Cos(phi);
	OutVector.Y = r * FMath::Sin(theta) * FMath::Sin(phi);
	OutVector.Z = r * FMath::Cos(theta);
}

void ACouchGame2025Character::CartesianToPolar(FVector Vector, float& OutR, float& OutTheta, float& OutPhi)
{
	OutR = Vector.Length();
	OutTheta = FMath::Acos(Vector.Z / OutR);
	OutPhi = FMath::Atan2(Vector.Y, Vector.X);
}

int ACouchGame2025Character::GetPriority()
{
	return 0;
}

bool ACouchGame2025Character::CanBeInteractWithSomethingInHand()
{
	return false;
}

void ACouchGame2025Character::Move(const FInputActionValue& Value)
{
	if (bIsWaiting) return;
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	InputMovement = MovementVector;

	//if (Controller != nullptr && !bIsGrabbing)
	//{} 
	//}
	float PosR;
	float PosTheta;
	float PosPhi;
	CartesianToPolar(GetActorLocation(), PosR, PosTheta, PosPhi);
	FVector NorthVector;
	PolarToCartesian(PosR, PosTheta - 0.1f, PosPhi, NorthVector);
	FVector EastVector;
	if (bIsInverted)
	{
		PolarToCartesian(PosR, PosTheta, PosPhi + 0.1f, EastVector);
	}
	else
	{
		PolarToCartesian(PosR, PosTheta, PosPhi - 0.1f, EastVector);
	}
	AddMovementInput(NorthVector, MovementVector.Y);
	AddMovementInput(EastVector, MovementVector.X);
}

void ACouchGame2025Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	Camera->Move(LookAxisVector);
}

void ACouchGame2025Character::Interact(const FInputActionValue& Value)
{
	// PAS UTILISER
	FHitResult Hit;
	FVector TraceStart = GetActorLocation();
	FVector TraceEnd = GetActorLocation() + GetActorForwardVector() * 1000.0f;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByObjectType(Hit, TraceStart, TraceEnd, ECC_WorldStatic, QueryParams);
	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_WorldStatic, QueryParams);

	if (Hit.bBlockingHit) {
		if (IInteractable* Interactable = Cast<IInteractable>(Hit.GetActor())) {
			Interactable->Interact(this);
		}
	}
}

void ACouchGame2025Character::HandlePlanetaryJumped()
{
	//
}

void ACouchGame2025Character::ToggleRopeMode(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, "ToggleRopeMode"); 
	// CableComponent->TryToggleRope(this);
}

void ACouchGame2025Character::MoveWhenGrabbing(FVector2D Movement)
{
	GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Emerald, TEXT("moving but grabbing"));
	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		//const FRotator YawRotation(Rotation.Roll, Rotation.Yaw, Rotation.Pitch);
		const FRotator YawRotation(Rotation);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Movement.Y);
		AddMovementInput(RightDirection, Movement.X);
	}
}

void ACouchGame2025Character::GrabbedByOtherPlayer(ACouchGame2025Character* Other)
{
	if (bIsWaiting) return;
	bIsGrabbedByAnotherPlayer = true;
	Other->OtherPlayer = this;
	Other->bIsGrabbingPlayer = true;
	SetActorEnableCollision(false);
	this->AttachToComponent(
		Other->GetMesh(),
		FAttachmentTransformRules(
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::KeepWorld,
			true),
			"Throw_Pos");
	//this->AttachToComponent(
	//	Other->GetMesh(),
	//	FAttachmentTransformRules(
	//		EAttachmentRule::SnapToTarget,
	//		EAttachmentRule::SnapToTarget,
	//		EAttachmentRule::SnapToTarget,
	//		true),
	//		"Throw_Pos");
	GetCharacterMovement()->SetMovementMode(MOVE_None);
	Other->bIsGrabbingPlayer = true;
}

void ACouchGame2025Character::StopMove()
{
	InputMovement = FVector2D::ZeroVector;
}

void ACouchGame2025Character::BeginPlay()
{
	TransfertSettings = GetDefault<UTransfertSettings>();
	Super::BeginPlay();
	Camera = ACouchCameraActor::CurrentCamera;
	SetRespawnLocation(GetActorLocation());
	if (UPlanetaryMovementComponent* PMC = Cast<UPlanetaryMovementComponent>(GetMovementComponent()))
	{
		PMC->OnPlanetaryJumped.AddDynamic(this, &ACouchGame2025Character::HandlePlanetaryJumped);
	}
}

void ACouchGame2025Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACouchGame2025Character::Transfert(const FInputActionValue& Value)
{
	FHitResult Hit;
	FVector TraceStart = GetActorLocation();
	FVector TraceEnd = GetActorLocation() + GetActorForwardVector() * 1000.0f;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Interactable, QueryParams);

	if (Hit.bBlockingHit) {
		if (IInteractable* Interactable = Cast<IInteractable>(Hit.GetActor())) {
			Interactable->Interact(this);
		}
	}
}

void ACouchGame2025Character::InvertCharacter()
{
	bIsInverted = !bIsInverted;
	UPlanetaryMovementComponent* MovementComponent;
	MovementComponent = Cast<UPlanetaryMovementComponent>(GetMovementComponent());
	MovementComponent->UseExternalGravityDirection = !MovementComponent->UseExternalGravityDirection;
}

void ACouchGame2025Character::InvertCamera()
{
	Camera->InvertCamera();
}

void ACouchGame2025Character::CallEventEndMovingAlongSpline()
{
	OnEndMovingAlongSpline.Broadcast();
}

void ACouchGame2025Character::SetGameplayCameraAsCamera(float TimeToBlend)
{
	UGameplayStatics::GetPlayerController(this, 0)->SetViewTargetWithBlend(Camera, TimeToBlend, TransfertSettings->CameraBlendType, 1.f, true);
}

void ACouchGame2025Character::SetSpecialCameraAsCamera(float TimeToBlend, AActor* InActor)
{
	UGameplayStatics::GetPlayerController(this, 0)->SetViewTargetWithBlend(InActor, TimeToBlend, TransfertSettings->CameraBlendType, 1.f, true);
}

void ACouchGame2025Character::Wait()
{
	bIsWaiting = true;
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Interactable, ECollisionResponse::ECR_Ignore);
}

void ACouchGame2025Character::StopWait()
{
	bIsWaiting = false;
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Interactable, ECollisionResponse::ECR_Block);
}

void ACouchGame2025Character::SetRespawnLocation(FVector InLocation)
{
	RespawnPoint = InLocation;
}

void ACouchGame2025Character::ResetPlayer()
{
	if (bIsInverted)
	{
		UPlanetaryMovementComponent* MovementComponent = Cast<UPlanetaryMovementComponent>(GetMovementComponent());
		MovementComponent->UseExternalGravityDirection = false;
		MovementComponent->SetGravityDirection(-MovementComponent->GetGravityDirection());
		MovementComponent->StopMovementImmediately();
	}
}

bool ACouchGame2025Character::Interact(ACouchGame2025Character* A)
{
	return false;
}

void ACouchGame2025Character::CheckForThrowPlayer()
{
	if (bIsAnyThrowTriggerToggled)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("2"));
		bAreBothTriggerToggled = true;

		if (bIsGrabbing && !bIsGrabbingPlayer) {
			PickupComponent->StopPickUp(this);
		}
		ThrowPlayer();
	} else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("1"));
		bIsAnyThrowTriggerToggled = true;
	}
}

void ACouchGame2025Character::ReleaseTrigger()
{
	if (bAreBothTriggerToggled)
	{
		bAreBothTriggerToggled = false;
	} else
	{
		bIsAnyThrowTriggerToggled = false;
	}
}

void ACouchGame2025Character::StopThrow()
{
	if (bIsAnyThrowTriggerToggled)
	{
		
	}
}
	
void ACouchGame2025Character::ThrowPlayer()
{
	
	if (OtherPlayer == nullptr || !bIsGrabbingPlayer) return;
	//SetActorEnableCollision(true);
	OtherPlayer->bIsGrabbedByAnotherPlayer = false;
	OtherPlayer->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
#pragma region test
	UCharacterMovementComponent* Move = OtherPlayer->GetCharacterMovement();
	FVector4 CharacterMovementValues = FVector4(Move->BrakingFrictionFactor, Move->GroundFriction, Move->BrakingFrictionFactor, Move->BrakingDecelerationWalking);
	Move->BrakingFrictionFactor = 0.f;
	Move->GroundFriction = 0.f;
	Move->BrakingFriction = 0.f;
	Move->BrakingDecelerationWalking = 0.f;
	OtherPlayer->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	FVector FwdVector = GetActorForwardVector();
	OtherPlayer->LaunchCharacter(FVector(
		FrontLaunchForce * 500.f * FwdVector.X,
		FrontLaunchForce * 500.f * FwdVector.Y,
		FrontLaunchForce * 500.f * FwdVector.Z),
		true,
		true);
	Move->BrakingFrictionFactor = CharacterMovementValues[0];
	Move->GroundFriction = CharacterMovementValues[1];
	Move->BrakingFriction = CharacterMovementValues[2];
	Move->BrakingDecelerationWalking = CharacterMovementValues[3];
	OtherPlayer->SetActorEnableCollision(true);
#pragma endregion

	PickupComponent->PickedUpPlayer = nullptr;
	bIsGrabbingPlayer = false;

	Cast<UPlanetaryMovementComponent>(OtherPlayer->GetMovementComponent())->UseExternalGravityDirection = true;
	OnThrowCharacter.Broadcast(OtherPlayer);
}

void ACouchGame2025Character::SetVisibility(bool IsVisible)
{
	GetMesh()->SetVisibility(IsVisible);
}

void ACouchGame2025Character::LookAtPlayer(const FInputActionValue& Value)
{
	Camera->LookAtPosition(GetActorLocation());
}