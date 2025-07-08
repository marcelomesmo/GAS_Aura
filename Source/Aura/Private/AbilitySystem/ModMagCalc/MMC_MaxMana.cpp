// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxMana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	/** Boiler Plate **/
	const FGameplayTagContainer* SourceTag = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTag = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTag;
	EvaluationParameters.TargetTags = TargetTag;
	/** End Boiler Plate **/

	/** Captures the Intelligence attribute **/
	float Intelligence = 0.f;
	GetCapturedAttributeMagnitude(IntDef, Spec, EvaluationParameters, Intelligence);
	Intelligence = FMath::Max<float>(Intelligence, 0.f);

	/** Captures the Player Level **/
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();
	
	return 50.f + 2.5 * Intelligence + 15.f * PlayerLevel;
}


