


#include "CouchGame2025/Runtime/Public/Gameplay/Icepool.h"

#include "Logging/StructuredLog.h"
#include "Components/BoxComponent.h"
#include "CouchGame2025/Runtime/Public/Global/CouchGame2025Character.h"

// Sets default values
AIcepool::AIcepool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WaterTriggerBox = CreateDefaultSubobject<UBoxComponent>("WaterTriggerBox");
	WaterTriggerBox->SetupAttachment(RootComponent);
	WaterTriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AIcepool::OnWaterBoxBeginOverlap);
	// WaterTriggerBox->OnComponentEndOverlap
}

// Called when the game starts or when spawned
void AIcepool::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIcepool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIcepool::OnWaterBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACouchGame2025Character* Character = Cast<ACouchGame2025Character>(OtherActor)) {
		if (!Character->IsWaterTankFull()) {
			Character->AddWater(GatherWater(Character->WaterAmountUntilFull()));
		}
	}
}

void AIcepool::StartGatherWater() {
	
}

void AIcepool::Burn()
{
	float OldIceVolume = IceAmount;
	IceAmount = FMath::Clamp(IceAmount - GetWorld()->GetDeltaSeconds(), 0, 1);
	WaterAmount += OldIceVolume - IceAmount;
	ElementUpdated();
}

float AIcepool::GatherWater(float MaxGatheredWater)
{
	float OldWaterVolume = WaterAmount;
	WaterAmount = FMath::Clamp(WaterAmount - GetWorld()->GetDeltaSeconds(), 0, MaxGatheredWater);
	ElementUpdated();
	return OldWaterVolume - WaterAmount;
}

void AIcepool::ElementUpdated() {
	OnElementUpdated.Broadcast(IceAmount, WaterAmount);
}


