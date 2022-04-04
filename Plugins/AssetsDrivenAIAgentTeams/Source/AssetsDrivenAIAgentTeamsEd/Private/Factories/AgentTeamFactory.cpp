// Fill out your copyright notice in the Description page of Project Settings.


#include "Factories/AgentTeamFactory.h"

#include "AssetsDrivenAIAgentTeamsEd.h"
#include "Assets/AgentTeamsPreset.h"
#include "AssetsDrivenAIAgentTeams/Public/assets/AgentTeam.h"
#define LOCTEXT_NAMESPACE "AssetsDrivenAiAgentTeamsEd"

UAgentTeamFactory::UAgentTeamFactory() 
{ 
	bCreateNew = true; 
	bEditAfterNew = true; 
	SupportedClass = UAgentTeam::StaticClass(); 
	//Subcategories.Add(SubcategoryName); 
}

uint32 UAgentTeamFactory::GetMenuCategories() const 
{ 
	return FAssetsDrivenAIAgentTeamsEdModule::GetMenuCategory();
}

FText UAgentTeamFactory::GetDisplayName() const 
{ 
	return NSLOCTEXT("AssetsDrivenAiAgentTeamsEd", "UAIAgentTeamName", "Agent Team"); 
}

const TArray<FText>& UAgentTeamFactory::GetMenuCategorySubMenus() const \
{ 
	return Subcategories; 
}

UObject* UAgentTeamFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) \
{ 
	const FString Name = FString(TEXT("AgentTeam_")) + InName.ToString(); 
	UAgentTeam* NewAsset = NewObject<UAgentTeam>(InParent, InClass, (*Name), Flags); 
	return NewAsset; 
}

FText FAgentTeamAssetTypeActions::GetName() const
{
	return NSLOCTEXT("AssetsDrivenAiAgentTeamsEd", "UAIAgentTeamName", "Agent Team");
}

uint32 FAgentTeamAssetTypeActions::GetCategories()
{
	return FAssetsDrivenAIAgentTeamsEdModule::GetMenuCategory();
}

UClass* FAgentTeamAssetTypeActions::GetSupportedClass() const
{
	return UAgentTeam::StaticClass();
}

FColor FAgentTeamAssetTypeActions::GetTypeColor() const
{
	return FColor::Purple;
}





UAgentTeamsPresetFactory::UAgentTeamsPresetFactory()
{
	bCreateNew = true; 
	bEditAfterNew = true; 
	SupportedClass = UAgentTeamsPreset::StaticClass(); 
}

FText UAgentTeamsPresetFactory::GetDisplayName() const
{
	return NSLOCTEXT("AssetsDrivenAiAgentTeamsEd", "UAIAgentTeamsPresetName", "Agent Teams Preset"); 
}

uint32 UAgentTeamsPresetFactory::GetMenuCategories() const
{
	return FAssetsDrivenAIAgentTeamsEdModule::GetMenuCategory();
}

const TArray<FText>& UAgentTeamsPresetFactory::GetMenuCategorySubMenus() const
{
	return Subcategories; 
}

UObject* UAgentTeamsPresetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	const FString Name = FString(TEXT("AgentTeamsPreset_")) + InName.ToString(); 
	UAgentTeamsPreset* NewAsset = NewObject<UAgentTeamsPreset>(InParent, InClass, (*Name), Flags); 
	return NewAsset; 
}

FText FAgentTeamsPresetAssetTypeActions::GetName() const
{
	return NSLOCTEXT("AssetsDrivenAiAgentTeamsEd", "UAIAgentTeamsPresetName", "Agent Teams Preset"); 
}

uint32 FAgentTeamsPresetAssetTypeActions::GetCategories()
{
	return FAssetsDrivenAIAgentTeamsEdModule::GetMenuCategory();
}

UClass* FAgentTeamsPresetAssetTypeActions::GetSupportedClass() const
{
	return UAgentTeamsPreset::StaticClass();
}

FColor FAgentTeamsPresetAssetTypeActions::GetTypeColor() const
{
	return FColor::Turquoise;
}

#undef LOCTEXT_NAMESPACE
