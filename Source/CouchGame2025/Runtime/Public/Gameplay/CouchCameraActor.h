#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "CouchCameraActor.generated.h"

class USpringArmComponent;

USTRUCT()
struct FPolar {

	GENERATED_BODY()

	float Theta;
	float Phi;
	float Radius;

	FPolar()
	{

	}

	FPolar(float InTheta, float InPhi, float InRadius)
	{
		Theta = InTheta;
		Phi = InPhi;
		Radius = InRadius;
	}

	FPolar(FVector InVector)
	{
		Radius = InVector.Length();
		Theta = FMath::Acos(InVector.Z / Radius);
		Phi = FMath::Atan2(InVector.Y, InVector.X);
	}

	~FPolar()
	{

	}
};

UCLASS()
class COUCHGAME2025_API ACouchCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	ACouchCameraActor(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void InvertCamera();

	UFUNCTION(BlueprintCallable)
	void Move(FVector2D Input);

	UFUNCTION()
	void LookAtPosition(FVector Position);

	static ACouchCameraActor* CurrentCamera;

	UFUNCTION(BlueprintImplementableEvent)
	float GetPitchValue();

	UFUNCTION()
	static ACouchCameraActor* GetCurrentCamera();

protected:
	UFUNCTION()
	void PolarToCartesian(float r, float theta, float phi, FVector& OutVector);

	UFUNCTION()
	void CartesianToPolar(FVector Vector, float& OutR, float& OutTheta, float& OutPhi);



	UFUNCTION(BlueprintCallable)
	void Zoom(float Input);

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void ToggleBlackHole();

	UPROPERTY(EditAnywhere)
	float LerpSpeed = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInverted;

	UPROPERTY(EditAnywhere)
	float InternDistance;

private:
	UPROPERTY(Category = CameraActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	FPolar TargetPositionPolar;

	UPROPERTY()
	FPolar CurrentPositionPolar;
};
