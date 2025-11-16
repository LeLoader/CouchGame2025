#include "CouchGame2025/Runtime/Public/PickUpObject/RessourceInjector.h"
#include "Component/RessourceContainerComponent.h"

ARessourceInjector::ARessourceInjector()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ARessourceInjector::BeginPlay()
{
    Super::BeginPlay();
}

void ARessourceInjector::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (CurrentSource == nullptr)
        return;

    if (IsFull() || CurrentSource->IsContainerEmpty())
    {
        StopTransferFromContainer();
        return;
    }

    float Wanted = TransferRate * DeltaSeconds;
    float Removed = CurrentSource->RemoveRessource(Wanted);
    if (Removed <= 0.f)
    {
        StopTransferFromContainer();
        return;
    }

    float Added = AddRessource(Removed);
    if (Added < Removed)
    {
        float ReturnAmount = Removed - Added;
        CurrentSource->AddRessource(ReturnAmount);
        StopTransferFromContainer();
    }

    if (CurrentSource->IsContainerEmpty())
    {
        StopTransferFromContainer();
    }
}

float ARessourceInjector::AddRessource(float Amount)
{
    if (Amount <= 0.f) return 0.f;
    float Space = FMath::Max(0.f, MaxRessourceAmount - CurrentRessourceAmount);
    float ToAdd = FMath::Min(Amount, Space);
    CurrentRessourceAmount += ToAdd;
    return ToAdd;
}

float ARessourceInjector::RemoveRessource(float Amount)
{
    if (Amount <= 0.f) return 0.f;
    float ToRemove = FMath::Min(Amount, CurrentRessourceAmount);
    CurrentRessourceAmount -= ToRemove;
    return ToRemove;
}

float ARessourceInjector::TransferFromContainerInstant(URessourceContainerComponent* Source, float Amount)
{
    if (Source == nullptr || Amount <= 0.f) return 0.f;

    float Removed = Source->RemoveRessource(Amount);
    if (Removed <= 0.f) return 0.f;

    float Added = AddRessource(Removed);
    if (Added < Removed)
    {
        float ReturnAmount = Removed - Added;
        Source->AddRessource(ReturnAmount);
    }
    return Added;
}

void ARessourceInjector::StartTransferFromContainer(URessourceContainerComponent* Source)
{
    if (Source == nullptr) return;
    CurrentSource = Source;
}

void ARessourceInjector::StopTransferFromContainer()
{
    CurrentSource = nullptr;
}

bool ARessourceInjector::IsFull() const
{
    return FMath::Abs(CurrentRessourceAmount - MaxRessourceAmount) < UE_KINDA_SMALL_NUMBER;
}

bool ARessourceInjector::IsEmpty() const
{
    return CurrentRessourceAmount < UE_KINDA_SMALL_NUMBER;
}