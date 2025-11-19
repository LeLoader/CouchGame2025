#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "CouchCameraActor.generated.h"

class USpringArmComponent;
class AInterestPoint;

UCLASS()
class COUCHGAME2025_API ACouchCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	ACouchCameraActor(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void SetCharacters(AActor* FirstCharacter, AActor* SecondCharacter);

protected:
	UFUNCTION()
	void PolarToCartesian(float r, float theta, float phi, FVector& OutVector);

	UFUNCTION()
	void CartesianToPolar(FVector Vector, float& OutR, float& OutTheta, float& OutPhi);

	UFUNCTION(BlueprintCallable)
	void Move(FVector2D Input);

	UFUNCTION(BlueprintCallable)
	void Zoom(float Input);

	virtual void BeginPlay() override;
	
	UFUNCTION()
	void ChangeDestination(AInterestPoint* NewInterestPoint);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector CalculateAveragePositions();

	UFUNCTION()
	bool IsInWholeCamera(FVector2D Position);

	UFUNCTION()
	bool isInCenterCamera(FVector2D Position);

	UPROPERTY(EditAnywhere)
	float LerpSpeed = 1.f;

	UPROPERTY(EditAnywhere, Category = "CouchGameCamera", meta = (Units = "deg"))
	float Angle = 45.f;

private:
	UPROPERTY(Category = CameraActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	TObjectPtr<AInterestPoint> CurrentInterestPoint;

	UPROPERTY()
	TArray<AActor*> Characters;

};