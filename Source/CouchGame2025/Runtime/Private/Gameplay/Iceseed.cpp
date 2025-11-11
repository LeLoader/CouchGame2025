


#include "Gameplay/Iceseed.h"

#include "Components/BoxComponent.h"
#include "Component/BurnComponent.h"
#include "Component/RessourceContainerComponent.h"


// Sets default values
AIceSeed::AIceSeed()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BurnTrigger = CreateDefaultSubobject<UBoxComponent>("BurnTrigger");
	BurnTrigger->SetupAttachment(Mesh);

	BurnComponent = CreateDefaultSubobject<UBurnComponent>("BurnComponent");
	BurnComponent->NumOfSourceToBurn = 2;

	IceContainer = CreateDefaultSubobject<URessourceContainerComponent>("IceContainer");
	IceContainer->SetRessourceType(FRessourceType::ICE);
	IceContainer->AddRessource(IceContainer->GetMaxRessourceAmount());

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
		IceContainer->OnContainerEmpty.Remove(Handle);
		});
}

// Called every frame
void AIceSeed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AIceSeed::Burn(float DeltaTime)
{
	IceContainer->InstantMoveRessource(DeltaTime, nullptr);
}

UBurnComponent* AIceSeed::GetBurnComponent()
{
	return BurnComponent;
}

