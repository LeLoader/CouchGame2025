    #include "CouchGame2025/Runtime/Public/PickUpObject/RessourceInjector.h"
    #include "Kismet/GameplayStatics.h"
    #include "GameFramework/Character.h"
    
    ARessourceInjector::ARessourceInjector()
    {
        PrimaryActorTick.bCanEverTick = false; // plus besoin de Tick avec la sphere
    
        MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
        RootComponent = MeshComponent;
    
        RessourceContainer = CreateDefaultSubobject<URessourceContainerComponent>(TEXT("RessourceContainer"));

        RessourceContainer->SetRessourceType(FRessourceType::WATER);
        
        ProximitySphere = CreateDefaultSubobject<USphereComponent>(TEXT("ProximitySphere"));
        ProximitySphere->SetupAttachment(RootComponent);
        ProximitySphere->SetSphereRadius(ProximityRadius);
        ProximitySphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    }
    
    void ARessourceInjector::BeginPlay()
    {
        Super::BeginPlay();
    
        ProximitySphere->OnComponentBeginOverlap.AddDynamic(this, &ARessourceInjector::OnProximityBeginOverlap);
        ProximitySphere->OnComponentEndOverlap.AddDynamic(this, &ARessourceInjector::OnProximityEndOverlap);
        //FDelegateHandle Handle;
        //Handle = RessourceContainer->OnContainerEmpty.AddWeakLambda(this, [this, Handle] {
        //    RessourceContainer->OnContainerEmpty.Remove(Handle);
        //    });
    }
    
    void ARessourceInjector::Tick(float DeltaSeconds)
    {
        Super::Tick(DeltaSeconds);
    }

    int ARessourceInjector::GetPriority()
    {
        return 4;
    }

    bool ARessourceInjector::CanBeInteractWithSomethingInHand()
    {
        return false;
    }

    bool ARessourceInjector::Interact(ACouchGame2025Character* Character)
    {
        if (FMath::IsNearlyEqual(
            RessourceContainer->GetCurrentRessourceAmount(),
            RessourceContainer->GetMaxRessourceAmount(),
            .1f))          
        {
            PlayerTryingToInteract = Character;
            OnInteract.Broadcast();
        }
        return true;
    }

    void ARessourceInjector::OnProximityBeginOverlap(UPrimitiveComponent* /*OverlappedComp*/, AActor* OtherActor,
                                                     UPrimitiveComponent* /*OtherComp*/, int32 /*OtherBodyIndex*/, bool /*bFromSweep*/, const FHitResult& /*SweepResult*/)
    {
        if (bIsFull) return;
    
        auto* Player = Cast<ACharacter>(OtherActor);
        if (!Player) return;
    
        URessourceContainerComponent* PlayerContainer = Player->FindComponentByClass<URessourceContainerComponent>();
        if (PlayerContainer)
        {
            PlayerContainer->StartMovingRessource(RessourceContainer);
        }
    }
    
    void ARessourceInjector::OnProximityEndOverlap(UPrimitiveComponent* /*OverlappedComp*/, AActor* OtherActor,
        UPrimitiveComponent* /*OtherComp*/, int32 /*OtherBodyIndex*/)
    {
    
        auto* Player = Cast<ACharacter>(OtherActor);
        if (!Player) return;
    
        URessourceContainerComponent* PlayerContainer = Player->FindComponentByClass<URessourceContainerComponent>();
        if (PlayerContainer)
        {
            PlayerContainer->StopMovingRessource(RessourceContainer);
        }
    }