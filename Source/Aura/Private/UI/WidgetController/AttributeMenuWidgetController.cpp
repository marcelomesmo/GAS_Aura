// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo);

	for (auto& Pair: AS->TagsToAttributes)
	{
		// Call the lambda whenever the attribute changes
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		}
		);
	}
}

void UAttributeMenuWidgetController::BroadCastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	// This is the Data Asset used for Attributes
	check(AttributeInfo);
	
	// TODO: this is going to be replaced later, refactor here: https://www.udemy.com/course/unreal-engine-5-gas-top-down-rpg/learn/lecture/39784204#questions/20672384/
	for (auto& Pair: AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
	// This is convoluted as fuk and I'm glad it's going to be replaced
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute)
{
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);	// AttributeSet comes from the parent UWidgetController
	AttributeInfoDelegate.Broadcast(Info);
}


