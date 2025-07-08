// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted;
	/** End Enemy Interface */

	/** Combat Interface **/
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface **/

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	// Don't need to be tagged as replicated because we are only checking on Server
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "Character Class Defaults")
	int32 Level = 1;
};
