// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AuraUserWidget")
	void SetWidgetController(UObject* InWidgetController);
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;	// We will get data from this Widget controller
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
