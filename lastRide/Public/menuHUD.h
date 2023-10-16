// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "menuHUD.generated.h"

/**
 * 
 */
UCLASS()
class LASTRIDE_API AmenuHUD : public AHUD
{
	GENERATED_BODY()

protected:

	// Storing reference to menu itself and its container which is a SWidget class
	TSharedPtr<class SMainMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;


	virtual void BeginPlay() override;
	
};
