// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AssetsDrivenAIAgentTeamsConfig.generated.h"

class UAgentTeamsPreset;
/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta=(DisplayName="Assets Driven AIAgent Teams"))
class ASSETSDRIVENAIAGENTTEAMS_API UAssetsDrivenAIAgentTeamsConfig : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(Config,EditAnywhere,Category="Default")
	TSoftObjectPtr<UAgentTeamsPreset> DefaultPreset;
};
