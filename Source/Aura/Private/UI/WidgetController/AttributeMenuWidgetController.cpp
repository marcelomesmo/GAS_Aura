// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo);

	/*
	for (auto& Pair: AS->TagsToAttributes)
	{
		// Call the lambda whenever the attribute changes
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		}
		);
	}*/
	
	for (const auto& Info : AttributeInfo->AttributeInformation)
	{
		// Call the lambda whenever the attribute changes
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Info.AttributeToGet).AddLambda(
		[this, &Info](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Info);
		}
		);
	}
}

void UAttributeMenuWidgetController::BroadCastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	// This is the Data Asset used for Attributes
	check(AttributeInfo);

	/*
	// TODO: this is going to be replaced later, refactor here: https://www.udemy.com/course/unreal-engine-5-gas-top-down-rpg/learn/lecture/39784204#questions/20672384/
	for (auto& Pair: AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
	// This is convoluted as fuk and I'm glad it's going to be replaced
	*/

	// Here we get the AttributeInformation (which is the TArray of data that is in our DataAsset) , and we just loop through that array provide the Tag to our helper function.
	for (const auto& Info: AttributeInfo->AttributeInformation)
	{
		BroadcastAttributeInfo(Info);
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FAuraAttributeInfo& Info) const
{
	// getting info from the DataAsset AttributeInfo based on the GameplayTag
	FAuraAttributeInfo NewInfo = Info;
	// Set the hidden Value in AttributeInfo DataAsset
	NewInfo.AttributeValue = Info.AttributeToGet.GetNumericValue(AttributeSet);	// AttributeSet comes from the parent UWidgetController
	// Broadcast for those who subscribe. IE the attribute menu widget in blueprint
	AttributeInfoDelegate.Broadcast(NewInfo);
}

/*
void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute)
{
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);	// AttributeSet comes from the parent UWidgetController
	AttributeInfoDelegate.Broadcast(Info);
}*/


