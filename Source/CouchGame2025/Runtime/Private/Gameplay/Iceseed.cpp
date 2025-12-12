


#include "Gameplay/Iceseed.h"

#include "Components/BoxComponent.h"
#include "Component/BurnComponent.h"
#include "Global/CouchGame2025Character.h"
#include "Component/RessourceContainerComponent.h"


// Sets default values
AIceSeed::AIceSeed()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BurnTrigger = CreateDefaultSubobject<UBoxComponent>("BurnTrigger");
	BurnTrigger->SetupAttachment(Mesh);

	WaterTrigger = CreateDefaultSubobject<UBoxComponent>("WaterTrigger");
	WaterTrigger->SetupAttachment(Mesh);
	WaterTrigger->OnComponentBeginOverlap.AddDynamic(this, &AIceSeed::OnWaterBoxBeginOverlap);
	WaterTrigger->OnComponentEndOverlap.AddDynamic(this, &AIceSeed::OnWaterBoxEndOverlap);

	BurnComponent = CreateDefaultSubobject<UBurnComponent>("BurnComponent");
	BurnComponent->NumOfSourceToBurn = 2;

	IceContainer = CreateDefaultSubobject<URessourceContainerComponent>("IceContainer");
	IceContainer->SetRessourceType(FRessourceType::ICE);
	IceContainer->AddRessource(IceContainer->GetMaxRessourceAmount());

	WaterContainer = CreateDefaultSubobject<URessourceContainerComponent>("WaterContainer");
	WaterContainer->SetRessourceType(FRessourceType::WATER);

	bCanBePickedUp = false;
}

// Called when the game starts or when spawned

void AIceSeed::BeginPlay()
{
	Super::BeginPlay();

	FDelegateHandle Handle;
	Handle = IceContainer->OnContainerEmpty.AddWeakLambda(this, [this, Handle] {
		OnIceSeedPickable.Broadcast();
		bCanBePickedUp = true;
		WaterContainer->AddRessource(WaterContainer->GetMaxRessourceAmount());
		IceContainer->OnContainerEmpty.Remove(Handle);
		});

	if (BurnComponent) {
		BurnComponent->OnBurnStarted.AddDynamic(this, &AIceSeed::HandleMelting);
	}
}


// Called every frame
void AIceSeed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AIceSeed::OnWaterBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ACouchGame2025Character>(OtherActor)) {
		ACouchGame2025Character* Character = Cast<ACouchGame2025Character>(OtherActor);
		WaterContainer->StartMovingRessource(Character->WaterTank);
	}
}

void AIceSeed::OnWaterBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<ACouchGame2025Character>(OtherActor)) {
		ACouchGame2025Character* Character = Cast<ACouchGame2025Character>(OtherActor);
		WaterContainer->StopMovingRessource(Character->WaterTank);
	}
}

void AIceSeed::Burn(float DeltaTime)
{
	IceContainer->InstantMoveRessource(DeltaTime, nullptr);
}

UBurnComponent* AIceSeed::GetBurnComponent()
{
	return BurnComponent;
}

void AIceSeed::HandleMelting()
{
	UE_LOG(LogTemp, Warning, TEXT("Ice Seed is melting"));
}