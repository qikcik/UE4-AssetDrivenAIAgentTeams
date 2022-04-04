// Fill out your copyright notice in the Description page of Project Settings.


#include "Helpers/AgentTeamEdHelperBlueprintLibrary.h"

#include "AssetToolsModule.h"
#include "Factories/AgentTeamFactory.h"

UAgentTeam* UAgentTeamEdHelperBlueprintLibrary::CreateAgentTeamWithDialog()
{
	FString Name;
	FString PackageName;

	UAgentTeamFactory* Factory = NewObject<UAgentTeamFactory>();
 
	FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
	UObject* Created = AssetToolsModule.Get().CreateAssetWithDialog(UAgentTeam::StaticClass(),Factory);
	if(Created)
		return  Cast<UAgentTeam>(Created);
	return nullptr;
}
