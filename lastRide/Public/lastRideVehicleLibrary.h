// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/SpringArmComponent.h"
#include "lastRideVehicleLibrary.generated.h"

class UWheeledVehicleMovementComponent;
class UPhysicalMaterial;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class LASTRIDE_API UlastRideVehicleLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "LastRide")
		static TArray<UPhysicalMaterial*> GetPhysicalMaterialsUnderTires(UWheeledVehicleMovementComponent* VehMovement);

	UFUNCTION(BlueprintCallable, Category = "LastRide")
		static float GetMaxSuspensionForce(UWheeledVehicleMovementComponent* VehMovement);

	UFUNCTION(BlueprintCallable, Category = "LastRide")
		static bool checkSlipThreshold(UWheeledVehicleMovementComponent* VehMovement, float LongSlipThresh, float LaSlipThresh);
	
	UFUNCTION(BlueprintCallable, Category = "LastRide")
		static bool zoom(USpringArmComponent* armThirdPerson,bool isThirdPerson);


};
