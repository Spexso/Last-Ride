// Fill out your copyright notice in the Description page of Project Settings.


#include "Lambo_car.h"

// Sets default values
ALambo_car::ALambo_car()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALambo_car::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALambo_car::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALambo_car::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

