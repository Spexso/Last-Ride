// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"
#include "menuHUD.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "MainMenu"

class FCoreStyle;

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	// Building UI

	// To prevent an error
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;
	
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);

	// Defined Menu Elements
	const FText TitleText = LOCTEXT("GameTitle", "Last Ride");
	const FText PlayText = LOCTEXT("PlayGame", "Play");
	const FText SettingsText = LOCTEXT("Settings", "Settings");
	const FText QuitText = LOCTEXT("QuitGame", "Quit Game");
	const FText Developer = LOCTEXT("Dev", "Credits");

	// Improvements on UI (changing font and size of it ext)
	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;


	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
				[
					SNew(SImage)
					.ColorAndOpacity(FColor::Black)
				]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
				[
					SNew(SVerticalBox)

					// Title text
					+ SVerticalBox::Slot()
					[
						SNew(STextBlock)
						/*.Text(TitleTextStyle)*/
						.Text(TitleText)
						.Justification(ETextJustify::Center)
					]

					// Play button
					+ SVerticalBox::Slot()
					.Padding(ButtonPadding)
					[
						SNew(SButton)
						.OnClicked(this, &SMainMenuWidget::onPlayClicked)
						[
							SNew(STextBlock)
							/*.Font(ButtonTextStyle)*/
							.Text(PlayText)
							.Justification(ETextJustify::Center)
						]
					]

					// Settings button
					+ SVerticalBox::Slot()
					.Padding(ButtonPadding)
					[
						SNew(SButton)
						[
							SNew(STextBlock)
							/*.Font(ButtonTextStyle)*/
							.Text(SettingsText)
							.Justification(ETextJustify::Center)
						]
					]

					// Credits button
					+ SVerticalBox::Slot()
					.Padding(ButtonPadding)
					[
						SNew(SButton)
						[
							SNew(STextBlock)
							/*.Font(ButtonTextStyle)*/
							.Text(Developer)
							.Justification(ETextJustify::Center)
						]
					]

					// Quit button
					+ SVerticalBox::Slot()
					.Padding(ButtonPadding)
					[
						SNew(SButton)
						.OnClicked(this, &SMainMenuWidget::onQuitClicked)
						[
							SNew(STextBlock)
							/*.Font(ButtonTextStyle)*/
							.Text(QuitText)
							.Justification(ETextJustify::Center)
						]
					]
				]
		];
	
}

// Runs when user clicks play and starts the game
FReply SMainMenuWidget::onPlayClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("GameStarted"));

	return FReply::Handled();
}

// Runs when user clicks quit game and close the game
FReply SMainMenuWidget::onQuitClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("Quit from Game"));

	return FReply::Handled();
	/*
	// If HUD is available get it and bind it to current player
	if (OwningHUD.IsValid())
	{
		if (APlayerController * PC = OwningHUD->PlayerOwner) {

			PC->ConsoleCommand("quit");
		}
	}
	
	return FReply::Handled();
	*/
}

#undef LOCTEXT_NAMESPACE
