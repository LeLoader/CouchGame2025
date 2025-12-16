// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/PlayerConstraint.h"


// Sets default values
APlayerConstraint::APlayerConstraint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerConstraint::BeginPlay()
{
	Super::BeginPlay();
	Cable = FindComponentByClass<UCableComponentBis>();
	ensure(Cable);
}

// Called every frame
void APlayerConstraint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

