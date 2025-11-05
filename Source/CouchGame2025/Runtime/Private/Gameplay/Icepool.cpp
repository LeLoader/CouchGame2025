


#include "CouchGame2025/Runtime/Public/Gameplay/Icepool.h"
#include "Logging/StructuredLog.h"

// Sets default values
AIcepool::AIcepool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void AIcepool::Burn()
{
	UE_LOGFMT(LogTemp, Log, "Burn");
}


