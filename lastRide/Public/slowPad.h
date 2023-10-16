// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "WheeledVehicle.h"
#include "WheeledVehicleMovementComponent.h"
#include "slowPad.generated.h"

UCLASS()
class LASTRIDE_API AslowPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AslowPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Slow effect 
	UFUNCTION(BlueprintCallable, Category = "Effect")
	void makeSlow(USkeletalMeshComponent* carMesh);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
