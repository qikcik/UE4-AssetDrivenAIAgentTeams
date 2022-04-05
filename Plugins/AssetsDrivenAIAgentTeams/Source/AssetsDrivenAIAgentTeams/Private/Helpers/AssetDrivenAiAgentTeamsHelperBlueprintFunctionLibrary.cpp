// Fill out your copyright notice in the Description page of Project Settings.


#include "Helpers/AssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary.h"

#include "Assets/AgentTeamsPreset.h"
#include "Config/AssetsDrivenAIAgentTeamsConfig.h"
#include "GameFramework/GameStateBase.h"
#include "Helpers/GameStateTeamsPresetOverridable.h"


FGenericTeamId UAssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary::GetIDFromTeam(UAgentTeam* InTeam, UObject* InWorldContext)
{
	UAgentTeamsPreset* Preset = GetActualPreset(InWorldContext);
	if(!ensureMsgf(Preset,TEXT("Ai Agent Teams Present is undefined in config and in actual gamestate"))) return FGenericTeamId::NoTeam;
	
	return Preset->GetIDFromTeam(InTeam);
}

UAgentTeam* UAssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary::GetTeamFromID(FGenericTeamId InId, UObject* InWorldContext)
{
	UAgentTeamsPreset* Preset = GetActualPreset(InWorldContext);
	if(!ensureMsgf(Preset,TEXT("Ai Agent Teams Present is undefined in config and in actual gamestate"))) return nullptr;

	return Preset->GetTeamFromID(InId);
}

UAgentTeamsPreset* UAssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary::GetActualPreset(UObject* InWorldContext)
{
	UAgentTeamsPreset* Preset = nullptr;
	
	if(InWorldContext)
		if(auto World = InWorldContext->GetWorld())
			if( AGameStateBase* GameState = World->GetGameState() )
				Preset = IGameStateTeamsPresetOverridable::Execute_GetOverrideTeamsPreset(GameState);
	
	if(!Preset)
		Preset = GetMutableDefault<UAssetsDrivenAIAgentTeamsConfig>()->DefaultPreset.Get();

	return Preset;
}
