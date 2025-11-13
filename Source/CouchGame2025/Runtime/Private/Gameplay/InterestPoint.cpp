


#include "CouchGame2025/Runtime/Public/Gameplay/InterestPoint.h"
#include "Components/SphereComponent.h"



// Sets default values
AInterestPoint::AInterestPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InfluenceZone = CreateDefaultSubobject<USphereComponent>(TEXT("Influence Zone"));
	InfluenceZone->SetupAttachment(RootComponent);
	InfluenceZone->SetCollisionResponseToAllChannels(ECR_Ignore);
	InfluenceZone->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	InfluenceZone->SetCollisionObjectType(ECC_GameTraceChannel1);
	InfluenceZone->SetEnableGravity(false);
	InfluenceZone->OnComponentBeginOverlap.AddDynamic(this, &AInterestPoint::OnOverlapBegin);


}

// Called when the game starts or when spawned
void AInterestPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInterestPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInterestPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnInfluenceZoneEnteredEvent.Broadcast(this);
}

FVector AInterestPoint::GetFollowPosition()
{
	return GetActorLocation();
}