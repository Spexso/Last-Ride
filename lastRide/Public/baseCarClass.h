// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "WheeledVehicle.h"
#include "WheeledVehicleMovementComponent.h"
#include "CollisionQueryParams.h"
#include "baseCarClass.generated.h"


/**
 * 
 */
UCLASS()
class LASTRIDE_API AbaseCarClass : public AWheeledVehicle
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	virtual void testF(bool tes);

	/* Resets the cars position without restarting level */
	/* If player wants to go back to start Presses R only if not moving*/
	UFUNCTION(BlueprintCallable, Category = "CustomReset")
	virtual void resetCar();
	
	UPROPERTY()
	int32 ItemCount;
	
	UFUNCTION()
	int32 returnItemCount();

	UFUNCTION(BlueprintCallable, Category = "Item")
	void incrementItemCount(float addN);

	UFUNCTION()
	void decreaseItemCount(float extN);

protected:
	// Main functions that has implementation on child
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	/* Stores the default player start location as Vector */
	UPROPERTY(BlueprintReadWrite, Category = "DefaultLocation")
	FVector defaultLocation = FVector::ZeroVector;


public:
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void applyEffect();

	/* Update in Air Pyhsics */
	UFUNCTION()
	void updateInAirControl(float DeltaTime);

	/* Jump action for car */
	UFUNCTION(BlueprintCallable, Category = "Effects")
	bool applyJump();

	/* Speed Boost action for car */
	UFUNCTION(BlueprintCallable, Category = "Effects")
	bool applyBoostS();


// 	UFUNCTION()
// 	FORCEINLINE class UWheeledVehicleMovementComponent* returnMovement(){ return  }

};
