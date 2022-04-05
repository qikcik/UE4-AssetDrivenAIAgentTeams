// Fill out your copyright notice in the Description page of Project Settings.


#include "Helpers/AssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary.h"

#include "Assets/AgentTeamsPreset.h"
#include "Settings/AssetsDrivenAIAgentTeamsSettings.h"
#include "GameFramework/GameStateBase.h"
#include "Interfaces/GameStateTeamsPresetOverridable.h"


FGenericTeamId UAssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary::GetIDFromTeam(UAgentTeam* InTeam, UObject* InWorldContext)
{
	UAgentTeamsPreset* Preset = GetActualPreset(InWorldContext);
	if(!ensureMsgf(Preset,TEXT("Ai fallback Agent Teams Present is undefined in settings and in actual gamestate"))) return FGenericTeamId::NoTeam;
	
	return Preset->GetIDFromTeam(InTeam);
}

UAgentTeam* UAssetDrivenAiAgentTeamsHelperBlueprintFunctionLibrary::GetTeamFromID(FGenericTeamId InId, UObject* InWorldContext)
{
	UAgentTeamsPreset* Preset = GetActualPreset(InWorldContext);
	if(!ensureMsgf(Preset,TEXT("Ai fallback Agent Teams Present is undefined in settings and in actual gamestate"))) return nullptr;

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
		Preset = GetMutableDefault<UAssetsDrivenAIAgentTeamsSettings>()->DefaultPreset.Get();

	return Preset;
}
