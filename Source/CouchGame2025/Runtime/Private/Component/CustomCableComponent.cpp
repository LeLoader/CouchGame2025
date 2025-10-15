


#include "CouchGame2025/Runtime/Public/Component/CustomCableComponent.h"

#include "Components/SphereComponent.h"
#include "Logging/StructuredLog.h"


// Sets default values for this component's properties
UCustomCableComponent::UCustomCableComponent()
{

}

void UCustomCableComponent::OnRegister() 
{

	Super::OnRegister();

	TArray<FVector> ParticlesLocations;
	GetCableParticleLocations(ParticlesLocations);

	for (FVector Location : ParticlesLocations) {
		USphereComponent* Collision = NewObject<USphereComponent>(this, USphereComponent::StaticClass());
		Collision->RegisterComponent();
		Collision->bHiddenInGame = true;
		Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Collisions.Add(Collision);
	}
}

void UCustomCableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TArray<FVector> ParticlesLocations;
	GetCableParticleLocations(ParticlesLocations);

	for (int i = 0; i < ParticlesLocations.Num(); i++) {
		FVector OldPosition = Collisions[i]->GetRelativeLocation();
		Collisions[i]->SetRelativeLocation(ParticlesLocations[i]);

		if (bDoCustomCollision) 
		{
			FCollisionQueryParams Params;
			ECollisionChannel TraceChannel = GetCollisionObjectType();
			FCollisionResponseParams ResponseParams(GetCollisionResponseToChannels());

			if (GetWorld()) {
				FHitResult Result;
				GetWorld()->SweepSingleByChannel(Result, OldPosition, ParticlesLocations[i], FQuat::Identity, TraceChannel, FCollisionShape::MakeSphere(0.5f * CableWidth), Params, ResponseParams);

				if (Result.bBlockingHit) {
					UE_LOGFMT(LogTemp, Display, "{0} collided with: {1}", GetName(), Result.GetActor()->GetName());
					DrawDebugSphere(GetWorld(), Result.ImpactPoint, DebugSize, 32, FColor::Red);
				}
			}
		}

		if (bShowCustomCollisions)
{
			DrawDebugSphere(GetWorld(), ParticlesLocations[i], DebugSize, 32, FColor::Cyan);
		}
	}
}


