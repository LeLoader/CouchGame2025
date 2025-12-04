#include "CouchGame2025/Runtime/Public/Gameplay/ABlackHole.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerStart.h"

AABlackHole::AABlackHole()
{
	PrimaryActorTick.bCanEverTick = false;

	BlackHoleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlackHoleMesh"));
	RootComponent = BlackHoleMesh;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetupAttachment(RootComponent);
	CollisionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AABlackHole::OnOverlapBegin);
}

void AABlackHole::BeginPlay()
{
	Super::BeginPlay();
}

void AABlackHole::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this)
	{
		return;
	}

	if (ACouchGame2025Character* DeadCharacter = Cast<ACouchGame2025Character>(OtherActor))
	{
		DeadCharacter->SetActorLocation(DeadCharacter->RespawnPoint);
		DeadCharacter->ResetPlayer();
	}
	else
	{
		OnTrashDestroyed.Broadcast(OtherActor);
		OtherActor->Destroy();
	}
}