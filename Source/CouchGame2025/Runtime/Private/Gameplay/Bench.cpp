


#include "Gameplay/Bench.h"
#include "Global/CouchGame2025Character.h"


// Sets default values
ABench::ABench()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Seat1 = CreateDefaultSubobject<USceneComponent>(TEXT("Seat1"));
	Seat1->SetupAttachment(GetStaticMeshComponent());
	Seat2 = CreateDefaultSubobject<USceneComponent>(TEXT("Seat2"));
	Seat2->SetupAttachment(GetStaticMeshComponent());
}

// Called when the game starts or when spawned
void ABench::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABench::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABench::CanBeInteractWithSomethingInHand()
{
	return true;
}

bool ABench::Interact(ACouchGame2025Character* A)
{
	if (Seat1UsedBy == A || Seat2UsedBy == A) {
		A->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		// ENABLE INPUT
		if (Seat1UsedBy == A) Seat1UsedBy = nullptr;
		else Seat2UsedBy = nullptr;
		return true;
	}
	else {
		if (!IsValid(Seat1UsedBy)) {

			A->AttachToComponent(Seat1, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			Seat1UsedBy = A;
			// DISABLE INPUT
			return true;
		}
		else if (!IsValid(Seat2UsedBy)) {
			A->AttachToComponent(Seat2, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			Seat2UsedBy = A;
			// DISABLE INPUT
			return true;
		}
		else {
			return false;
		}
	}
}

int ABench::GetPriority()
{
	return 4;
}

