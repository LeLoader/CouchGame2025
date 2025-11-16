#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Component/RessourceContainerComponent.h"
#include "RessourceInjector.generated.h"

UCLASS(Blueprintable)
class COUCHGAME2025_API ARessourceInjector : public AActor
{
    GENERATED_BODY()

public:
    ARessourceInjector();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ressource")
    FRessourceType RessourceType;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ressource")
    float MaxRessourceAmount = 1.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ressource")
    float CurrentRessourceAmount = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Transfer")
    float TransferRate = 1.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transfer")
    URessourceContainerComponent* CurrentSource = nullptr;

public:
    UFUNCTION(BlueprintCallable, Category = "Ressource")
    float AddRessource(float Amount);

    UFUNCTION(BlueprintCallable, Category = "Ressource")
    float RemoveRessource(float Amount);

    UFUNCTION(BlueprintCallable, Category = "Transfer")
    float TransferFromContainerInstant(URessourceContainerComponent* Source, float Amount);

    UFUNCTION(BlueprintCallable, Category = "Transfer")
    void StartTransferFromContainer(URessourceContainerComponent* Source);

    UFUNCTION(BlueprintCallable, Category = "Transfer")
    void StopTransferFromContainer();

    UFUNCTION(BlueprintGetter, Category = "Ressource")
    bool IsFull() const;

    UFUNCTION(BlueprintGetter, Category = "Ressource")
    bool IsEmpty() const;
};