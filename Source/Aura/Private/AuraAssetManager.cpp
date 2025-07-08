// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"

#include "AuraGameplayTags.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);
	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

// This starts bootstrap for the game
void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	// Load native tags
	// TODO: This will be deprecated after we replace GameplayTags singleton with tags macro
	//FAuraGameplayTags::InitializeNativeGameplayTags();
}
