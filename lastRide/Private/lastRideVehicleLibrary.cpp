// Fill out your copyright notice in the Description page of Project Settings.


#include "lastRideVehicleLibrary.h"
#include "WheeledVehicleMovementComponent.h"


TArray<UPhysicalMaterial*> UlastRideVehicleLibrary::GetPhysicalMaterialsUnderTires(UWheeledVehicleMovementComponent* VehMovement)
{
	TArray<UPhysicalMaterial*> Mats;

	if (VehMovement) {

		for (UVehicleWheel* Wheel : VehMovement->Wheels) {

			Mats.Emplace(Wheel->GetContactSurfaceMaterial());

		}
	}
	return Mats;
}

float UlastRideVehicleLibrary::GetMaxSuspensionForce(UWheeledVehicleMovementComponent* VehMovement)
{
	if (VehMovement) {

		return VehMovement->GetMaxSpringForce();

	}
	else {

		return 0.0f;
	}
}

bool UlastRideVehicleLibrary::checkSlipThreshold(UWheeledVehicleMovementComponent* VehMovement, float LongSlipThresh, float LatSlipThresh)
{
	if (VehMovement) {

		float Long = FMath::Clamp<float>(LongSlipThresh, 0, 1);

		float Lat = FMath::Clamp<float>(LatSlipThresh, 0, 1);

		return VehMovement->CheckSlipThreshold(Long, Lat);

	}
	else {

		return false;
	}
}

bool UlastRideVehicleLibrary::zoom(USpringArmComponent* armThirdPerson, bool isThirdPerson) {
	
	float currentLength = armThirdPerson->TargetArmLength;
	float tempLenght;

	if (isThirdPerson) {

			tempLenght = armThirdPerson->TargetArmLength + (currentLength * -10);


			armThirdPerson->TargetArmLength = tempLenght;
			return true;
	}

	return false;
}


