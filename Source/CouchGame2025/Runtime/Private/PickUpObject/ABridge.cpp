#include "ABridge.h"

// Sets default values
AABridge::AABridge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AABridge::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABridge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}