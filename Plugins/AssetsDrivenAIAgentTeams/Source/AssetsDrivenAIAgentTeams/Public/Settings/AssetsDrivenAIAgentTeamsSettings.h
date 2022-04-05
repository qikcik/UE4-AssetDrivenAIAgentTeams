// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DeveloperSettings/Public/Engine/DeveloperSettings.h"
#include "AssetsDrivenAIAgentTeamsSettings.generated.h"

class UAgentTeamsPreset;

UCLASS(config = Game, defaultconfig, meta=(DisplayName="Assets Driven AIAgent Teams"))
class ASSETSDRIVENAIAGENTTEAMS_API UAssetsDrivenAIAgentTeamsSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UAssetsDrivenAIAgentTeamsSettings(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(Config,EditAnywhere,Category="Default")
	TSoftObjectPtr<UAgentTeamsPreset> DefaultPreset;
};
