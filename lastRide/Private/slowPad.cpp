// Fill out your copyright notice in the Description page of Project Settings.


#include "slowPad.h"

// Sets default values
AslowPad::AslowPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AslowPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// The Slow effect that will be applied to car 
void AslowPad::makeSlow(USkeletalMeshComponent* carMesh) {

	/* Change rate of Vector */
	float changeVRate = -600.f;

	/* Multiply and  Set the new vector */
	FVector newV = UKismetMathLibrary::Multiply_VectorFloat(GetActorRightVector(), changeVRate);

	
	// Apply slow effect
	carMesh->SetPhysicsLinearVelocity(newV, true);
	
}


// Called every frame
void AslowPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

