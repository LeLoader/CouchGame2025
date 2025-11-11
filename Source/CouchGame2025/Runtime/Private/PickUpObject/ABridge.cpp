#include "CouchGame2025/Runtime/Public/PickUpObject/ABridge.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Engine/World.h"

AABridge::AABridge()
{
    PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = Root;

    StartPoint = CreateDefaultSubobject<USceneComponent>(TEXT("StartPoint"));
    StartPoint->SetupAttachment(Root);

    EndPoint = CreateDefaultSubobject<USceneComponent>(TEXT("EndPoint"));
    EndPoint->SetupAttachment(Root);

    BridgeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BridgeMesh"));
    BridgeMesh->SetupAttachment(Root);

    bIsDeployed = false;
    BridgeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    BridgeMesh->SetVisibility(false);
}

void AABridge::BeginPlay()
{
    Super::BeginPlay();

    if (BridgeMesh && BridgeMesh->GetStaticMesh())
    {
        const FVector MeshSize = BridgeMesh->GetStaticMesh()->GetBoundingBox().GetSize();
        OriginalMeshLength = MeshSize.X > KINDA_SMALL_NUMBER ? MeshSize.X : 1.f;
        InitialMeshScale = BridgeMesh->GetComponentScale();
    }

    APlayerController* PC = GetWorld() ? GetWorld()->GetFirstPlayerController() : nullptr;
    if (!PC) return;

    EnableInput(PC);

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PC->InputComponent))
    {
        if (ToggleBridgeAction)
        {
            EnhancedInput->BindAction(ToggleBridgeAction, ETriggerEvent::Started, this, &AABridge::ToggleBridge);
        }
    }
}

void AABridge::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsDeployed)
    {
        UpdateBridgeTransform();
    }
}

void AABridge::ToggleBridge()
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!PlayerPawn) return;

    const FVector PlayerLoc = PlayerPawn->GetActorLocation();
    const float DistToStart = FVector::Dist(PlayerLoc, StartPoint->GetComponentLocation());
    const float DistToEnd = FVector::Dist(PlayerLoc, EndPoint->GetComponentLocation());

    if (DistToStart <= InteractionDistance || DistToEnd <= InteractionDistance)
    {
        bIsDeployed = !bIsDeployed;
        UpdateBridgeState();
    }
}

void AABridge::UpdateBridgeState()
{
    if (bIsDeployed)
    {
        BridgeMesh->SetVisibility(true);
        BridgeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        UpdateBridgeTransform();
    }
    else
    {
        BridgeMesh->SetVisibility(false);
        BridgeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }
}

void AABridge::UpdateBridgeTransform()
{
    if (!StartPoint || !EndPoint || !BridgeMesh) return;

    const FVector A = StartPoint->GetComponentLocation();
    const FVector B = EndPoint->GetComponentLocation();
    const FVector Dir = B - A;
    const float Distance = Dir.Size();
    if (Distance <= KINDA_SMALL_NUMBER) return;

    const FVector Mid = (A + B) * 0.5f;

    const FRotator Rot = Dir.Rotation();

    const float ScaleX = (Distance / OriginalMeshLength) * InitialMeshScale.X;
    FVector NewScale = InitialMeshScale;
    NewScale.X = ScaleX;
    NewScale.Y = InitialMeshScale.Y * WidthHeightScale;
    NewScale.Z = InitialMeshScale.Z * WidthHeightScale;

    BridgeMesh->SetWorldScale3D(NewScale);

    FVector MeshCenterLocal = FVector::ZeroVector;
    if (BridgeMesh->GetStaticMesh())
    {
        MeshCenterLocal = BridgeMesh->GetStaticMesh()->GetBoundingBox().GetCenter();
    }

    const FVector ScaledCenterLocal = MeshCenterLocal * NewScale;

    const FVector CenterOffsetWorld = Rot.RotateVector(ScaledCenterLocal);
    const FVector DesiredWorldLocation = Mid - CenterOffsetWorld;

    BridgeMesh->SetWorldLocation(DesiredWorldLocation);
    BridgeMesh->SetWorldRotation(Rot);
}