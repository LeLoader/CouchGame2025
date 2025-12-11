#include "Gameplay/Icepool.h"

#include "Logging/StructuredLog.h"
#include "Components/BoxComponent.h"
#include "Component/RessourceContainerComponent.h"
#include "Global/CouchGame2025Character.h"
#include "Component/BurnComponent.h"

// Sets default values
AIcepool::AIcepool()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WaterTriggerBox = CreateDefaultSubobject<UBoxComponent>("WaterTriggerBox");
	WaterTriggerBox->SetupAttachment(RootComponent);
	WaterTriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AIcepool::OnWaterBoxBeginOverlap);
	WaterTriggerBox->OnComponentEndOverlap.AddDynamic(this, &AIcepool::OnWaterBoxEndOverlap);

	IceContainer = CreateDefaultSubobject<URessourceContainerComponent>(TEXT("IceContainer"));
	IceContainer->AddRessource(IceContainer->GetMaxRessourceAmount());
	IceContainer->SetRessourceType(FRessourceType::ICE);
	WaterContainer = CreateDefaultSubobject<URessourceContainerComponent>(TEXT("WaterContainer"));
	WaterContainer->SetRessourceType(FRessourceType::WATER);

	BurnComponent = CreateDefaultSubobject<UBurnComponent>("BurnComponent");
}

// Called when the game starts or when spawned
void AIcepool::BeginPlay()
{
	Super::BeginPlay();

	FDelegateHandle Handle;
	Handle = IceContainer->OnContainerEmpty.AddWeakLambda(this, [this, Handle] {
		WaterContainer->AddRessource(WaterContainer->GetMaxRessourceAmount());
		IceContainer->OnContainerEmpty.Remove(Handle);
		});
}


void AIcepool::OnWaterBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ACouchGame2025Character>(OtherActor)) {
		ACouchGame2025Character* Character = Cast<ACouchGame2025Character>(OtherActor);
		WaterContainer->StartMovingRessource(Character->WaterTank);
	}
}

void AIcepool::OnWaterBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<ACouchGame2025Character>(OtherActor)) {
		ACouchGame2025Character* Character = Cast<ACouchGame2025Character>(OtherActor);
		WaterContainer->StopMovingRessource(Character->WaterTank);
	}
}

void AIcepool::Burn(float DeltaTime)
{
	BP_OnIceMelt();
	IceContainer->InstantMoveRessource(DeltaTime, nullptr);
}

UBurnComponent* AIcepool::GetBurnComponent()
{
	return BurnComponent;
}

