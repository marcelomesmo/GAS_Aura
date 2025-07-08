// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/*
	 * Primary Attributes
	 */
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"), FString("Increases physical damage")
		);

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"), FString("Increases magical damage")
		);
	
	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Resilience"), FString("Increases Armor and Armor Penetration")
		);
	
	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Vigor"), FString("Increases Health")
		);
	/*
	 * Secondary Attributes
	 */
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Armor"),
		FString("Reduces damage taken, improves Block Chance")
		);

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ArmorPenetration"),
		FString("Ignores Percentage of enemy Armor, increases Critical Hit Chance")
		);

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.BlockChance"),
		FString("Chance to cut incoming damage in half")
		);
	
	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitChance"),
		FString("Chance to double damage plus critical hit bonus")
		);
	
	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitDamage"),
		FString("Bonus damage added when a critical hit is scored")
		);

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitResistance"),
		FString("Reduces Critical Hit Chance of attacking enemies")
		);
	
	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.HealthRegeneration"),
		FString("Amount of Health regenerated every 1 second")
		);

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ManaRegeneration"),
		FString("Amount of Mana regenerated every 1 second")
		);

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxHealth"),
		FString("Maximum amount of Health obtainable")
		);

	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxMana"),
		FString("Maximum amount of Mana obtainable")
		);
}
/*
namespace AuraGameplayTags
{
	// Primary
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Primary_Strength, "Attributes.Primary.Strength");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Primary_Intelligence, "Attributes.Primary.Intelligence");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Primary_Resilience, "Attributes.Primary.Resilience");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Primary_Vigor, "Attributes.Primary.Vigor");
 
	// Secondary
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_Armor, "Attributes.Secondary.Armor");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_ArmorPenetration, "Attributes.Secondary.ArmorPenetration");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_BlockChance, "Attributes.Secondary.BlockChance");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_CriticalHitChance, "Attributes.Secondary.CriticalHitChance");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_CriticalHitDamage, "Attributes.Secondary.CriticalHitDamage");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_CriticalHitResistance, "Attributes.Secondary.CriticalHitResistance");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_HealthRegeneration, "Attributes.Secondary.HealthRegeneration");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_ManaRegeneration, "Attributes.Secondary.ManaRegeneration");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_MaxHealth, "Attributes.Secondary.MaxHealth");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Secondary_MaxMana, "Attributes.Secondary.MaxMana");
 
	// Vitals
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Vitals_Health, "Attributes.Vitals.Health");
	UE_DEFINE_GAMEPLAY_TAG(Attributes_Vitals_Mana, "Attributes.Vitals.Mana");
}*/