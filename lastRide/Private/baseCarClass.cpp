// Fill out your copyright notice in the Description page of Project Settings.


#include "baseCarClass.h"

/* Define behavior for ease of use / quality of life */
static const FName NAME_SteerInput("MoveRight");
static const FName NAME_ThrottleInput("MoveForwards");


void AbaseCarClass::testF(bool tes)
{

	UE_LOG(LogTemp, Warning, TEXT("Testing class build"));
}

/* Sets the Item count */
/* Checks if Item count is larger than 9 */
/* Player item count cant exceed 9 */
void AbaseCarClass::incrementItemCount(float addN) {
	
	if ((returnItemCount() + addN) > 9) {

		UE_LOG(LogTemp, Warning, TEXT("Item count can not exceed 9!, could not add"));

	}
	else
		ItemCount = returnItemCount() + addN;
}

void AbaseCarClass::decreaseItemCount(float extN)
{
	if ((returnItemCount() - extN) < 0) {

		UE_LOG(LogTemp, Warning, TEXT("Item count can not exceed 0!, could not extract"));

	}
	else
		ItemCount = returnItemCount() - extN;
}

/* Returns the number of items that car has collected */
int32 AbaseCarClass::returnItemCount() {

	return ItemCount;
}

void AbaseCarClass::BeginPlay() 
{
	Super::BeginPlay();

	/* Initialize the ItemCount */
	ItemCount = 0;

	/*
	// Get collision component and assign it to proper function
	if (auto mesh = GetMesh())
	{
		mesh->OnComponentBeginOverlap.AddDynamic(this, &AbaseCarClass::onBeginOverlap);
	}
	*/

	// Get default location so car can be respawned there
	defaultLocation = this->GetActorLocation();


	UE_LOG(LogTemp, Warning, TEXT("BeginPlay initialized succesfully"));
}

void AbaseCarClass::Tick(float DeltaSeconds) {

	Super::Tick(DeltaSeconds);

	updateInAirControl(DeltaSeconds);
}

// Resets the car's initial state
void AbaseCarClass::resetCar()
{
	/* If upside down */
	FRotator rotationRate = FRotator(0.f, 0.f, 0.f);
	FVector moveUpRate = FVector(0.f, 100.f, 0.f);

	UE_LOG(LogTemp, Log, TEXT("Car reset initiated"));

	/* Get vehicle movement component and check if its available */
	if (UWheeledVehicleMovementComponent* carMovComp = GetVehicleMovementComponent()) {

		//Stop the car's velocity in all directions and stop the engine
		carMovComp->StopMovementImmediately();
		carMovComp->UpdatedPrimitive->SetPhysicsLinearVelocity(FVector::ZeroVector, false);

	}

	// Move little up before rotating the car
	FVector newLocation =  UKismetMathLibrary::Add_VectorVector(defaultLocation, moveUpRate);
	
	this->TeleportTo(defaultLocation, rotationRate, false, false);

	/* Buggy implementation */
	//this->SetActorLocation(defaultLocation,false,nullptr,ETeleportType::TeleportPhysics);
	/*
	// Removes the APawn from game
	Reset();
	*/
}


/* Overridden function */
void AbaseCarClass::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {

	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/* Applies the various effects if Item picked up */
/* Rework needed same changes happened in game design */
void AbaseCarClass::applyEffect() {

	/*GetVehicleMovementComponent()->SetThrottleInput(0.0f);*/
	UE_LOG(LogTemp, Warning, TEXT("Effect applied"));
	UE_LOG(LogTemp, Warning, TEXT("Item count is = %d"), returnItemCount());
	//AbaseCarClass::makeJump();
	//AbaseCarClass::applyBoostS();
}

void AbaseCarClass::updateInAirControl(float DeltaTime)
{
	/*UE_LOG(LogTemp, Warning, TEXT("Testing Air Control"));*/

	if (UWheeledVehicleMovementComponent* car = GetVehicleMovementComponent()) {

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);

		const FVector TraceStart = GetActorLocation() + FVector(0.f, 0.f, 50.f);
		const FVector TraceEnd = GetActorLocation() - FVector(0.f, 0.f, 200.f);

		FHitResult Hit;

		/* Check if car is flipped on its side, and check if car is in the air */
		const bool bInAir = !GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, QueryParams);
		const bool bNotGrounded = FVector::DotProduct(GetActorUpVector(), FVector::UpVector) < 0.1f;

		/* Only allow in air-movement if we are not on the ground or in the air completely */
		if (bInAir || bNotGrounded) {

			// Grab Throttle and Steering inputs
			const float ForwardInput = InputComponent->GetAxisValue(NAME_ThrottleInput);
			const float RightInput = InputComponent->GetAxisValue(NAME_SteerInput);

			/* In car is grounded allow player to roll the car over */
			const float AirMovementForcePitch = 1.5f;
			// if car is flipped over force value is 20 otherwise 3 
			const float AirMovementForceRoll = !bInAir && bNotGrounded ? 5.f : 3.f;

			if(UPrimitiveComponent* carMesh = car->UpdatedPrimitive)
			{
				//Angle that car will stop moving
				const FVector MovementVector = FVector(RightInput * -AirMovementForcePitch, ForwardInput * AirMovementForcePitch, 0.f) * DeltaTime * 150.f;

				//Put the MovementVector value in car's space so it could be applied correctly
				const FVector NewAngularMovement = GetActorRotation().RotateVector(MovementVector);

				carMesh->SetPhysicsAngularVelocity(NewAngularMovement, true);
			}
		}
	}
}

// Cost of action is 3 power up 
bool AbaseCarClass::applyJump() {

	// Check if power is enough for action
	if (returnItemCount() < 3) {

		UE_LOG(LogTemp, Warning, TEXT("Not enough power for Jump"));
		//Widget Call

		return false;
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Jump Effect"));

		/* Jump Vector of vehicle */
		FVector jumpV = FVector(200.f, 200.f, 1200.f);

		/* Get vehicle movement component and check if its available */

		if (UWheeledVehicleMovementComponent* carMovComp = GetVehicleMovementComponent()) {

			carMovComp->UpdatedPrimitive->SetPhysicsLinearVelocity(jumpV, true);
		}

		decreaseItemCount(3);

		return true;
	}
	
	
}

// Cost of action is 4 power up 
bool AbaseCarClass::applyBoostS()
{
	float changeVRate = 1000;

	/* Speed Boost Vector of vehicle */
	FVector speedBoostedV = UKismetMathLibrary::Multiply_VectorFloat(GetActorForwardVector(), changeVRate);

	/* Get vehicle movement component and check if its available */

	if(returnItemCount() < 4 ){

		UE_LOG(LogTemp, Warning, TEXT("Not enough power for Speed Boost"));
		//Widget Call Warn Player

		return false;
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Speed Boost Effect"));

		if (UWheeledVehicleMovementComponent* carMovComp = GetVehicleMovementComponent()) {


			carMovComp->UpdatedPrimitive->SetPhysicsLinearVelocity(speedBoostedV, true);
		}
		
		decreaseItemCount(4);
		
		return true;
	}
	
}


