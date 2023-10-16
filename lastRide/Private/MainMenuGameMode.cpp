// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "menuHUD.h"
#include "MenuController.h"

AMainMenuGameMode::AMainMenuGameMode() {

	// Set default pawn to blueprinted class
	static ConstructorHelpers::FClassFinder<APawn> carPawnBPClass(TEXT("/Game/Vehicles/Toronto_car/Base/baseCar_PB"));
	if (carPawnBPClass.Class != NULL) {

		DefaultPawnClass = carPawnBPClass.Class;
	}

	PlayerControllerClass = AMenuController::StaticClass();
	HUDClass = AmenuHUD::StaticClass();
}

