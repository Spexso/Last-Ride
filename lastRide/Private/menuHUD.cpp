// Fill out your copyright notice in the Description page of Project Settings.


#include "menuHUD.h"
#include "SMainMenuWidget.h"
#include "Widgets/SWeakWidget.h"
// To add something to screen we need Engine pointer that comes from Engine.h
#include "Engine/Engine.h"

void AmenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport)
	{
		// Passing our HUD into the widget
		MenuWidget = SNew(SMainMenuWidget).OwningHUD(this);

		// Adding our Menu widget to Widget container and then binding Widget Container to GameViewPort
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
	}
}
