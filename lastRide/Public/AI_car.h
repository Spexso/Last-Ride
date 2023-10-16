// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AI_car.generated.h"

/**
 * 
 */
UCLASS()
class LASTRIDE_API UAI_car : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Ai")
	static void testFunc(FString text);
};
