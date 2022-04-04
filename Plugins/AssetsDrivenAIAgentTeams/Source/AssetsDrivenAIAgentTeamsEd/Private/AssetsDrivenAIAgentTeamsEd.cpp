// Copyright Epic Games, Inc. All Rights Reserved.


#include "AssetsDrivenAIAgentTeamsEd.h"

#include "AssetToolsModule.h"
#include "Factories/AgentTeamFactory.h"

#define LOCTEXT_NAMESPACE "FAssetsDrivenAIAgentTeamsEdModule"
EAssetTypeCategories::Type FAssetsDrivenAIAgentTeamsEdModule::MenuCategory;

void FAssetsDrivenAIAgentTeamsEdModule::StartupModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	FAssetsDrivenAIAgentTeamsEdModule::MenuCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("FAssetsDrivenAIAgentTeamsEd")), LOCTEXT("AgentTeamsCategory", "Agent Teams"));
	
	auto RegisterAssetTypeAction = [&](TSharedRef<IAssetTypeActions> Action)
	{
		AssetTools.RegisterAssetTypeActions(Action);
		CreatedAssetTypeActions.Add(Action);
	};

	RegisterAssetTypeAction(MakeShareable(new FAgentTeamAssetTypeActions));
}

void FAssetsDrivenAIAgentTeamsEdModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (auto CreatedAssetTypeAction : CreatedAssetTypeActions)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeAction.ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();
}

EAssetTypeCategories::Type FAssetsDrivenAIAgentTeamsEdModule::GetMenuCategory()
{
	return MenuCategory;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAssetsDrivenAIAgentTeamsEdModule, AssetsDrivenAIAgentTeamsEd)