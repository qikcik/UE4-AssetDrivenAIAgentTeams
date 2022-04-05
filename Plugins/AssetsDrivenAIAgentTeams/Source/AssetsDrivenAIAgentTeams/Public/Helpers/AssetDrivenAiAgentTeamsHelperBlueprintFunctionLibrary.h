// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "UObject/Object.h"
#include "AssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary.generated.h"

class UAgentTeamsPreset;
class UAgentTeam;

UCLASS(meta=(ToolTip="base class for access to asset driven AiAgent teams system"))
class ASSETSDRIVENAIAGENTTEAMS_API UAssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure,Category="AgentTeams",meta=(WorldContext="InWorldContext"))
	static FGenericTeamId GetIDFromTeam(UAgentTeam* InTeam, UObject* InWorldContext);

	UFUNCTION(BlueprintPure,Category="AgentTeams",meta=(WorldContext="InWorldContext"))
	static UAgentTeam* GetTeamFromID(FGenericTeamId InTeam, UObject* InWorldContext);
	
	UFUNCTION(BlueprintPure,Category="AgentTeams",meta=(WorldContext="InWorldContext"))
	static UAgentTeamsPreset* GetActualPreset(UObject* InWorldContext);
};
