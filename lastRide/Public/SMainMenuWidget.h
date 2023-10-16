// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"



/**
 * 
 */
class SMainMenuWidget : public SCompoundWidget
{

public:

	SLATE_BEGIN_ARGS(SMainMenuWidget){}

	SLATE_ARGUMENT(TWeakObjectPtr<class AmenuHUD>, OwningHUD)

	SLATE_END_ARGS()

	/* every widget needs construction function  */
	void Construct(const FArguments& InArgs);

	FReply onPlayClicked() const;
	FReply onQuitClicked() const;

	/* The HUD that created this widget */
	/* Since Compound widgets are not U objects garbage collector does not work for them
	   So we will manage it ourselves by creating TWeakObjectPtr
	 */
	TWeakObjectPtr<class AmenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override {
		return true; 
	};
};
