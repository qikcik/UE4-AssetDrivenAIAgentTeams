// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AssetTypeActions_Base.h"

#include "AgentTeamFactory.generated.h"

UCLASS()
class ASSETSDRIVENAIAGENTTEAMSED_API UAgentTeamFactory final : public UFactory
{
	GENERATED_BODY()
public:
	UAgentTeamFactory();
	virtual FText GetDisplayName() const override; 
	virtual uint32 GetMenuCategories() const override; 
	virtual const TArray<FText>& GetMenuCategorySubMenus() const override;
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
private:
	TArray<FText> Subcategories;
};

class FAgentTeamAssetTypeActions final : public FAssetTypeActions_Base 
{
	virtual FText GetName() const override; 
	virtual uint32 GetCategories() override; 
	virtual UClass* GetSupportedClass() const override; 
	virtual FColor GetTypeColor() const override;
};



UCLASS()
class ASSETSDRIVENAIAGENTTEAMSED_API UAgentTeamsPresetFactory final : public UFactory
{
	GENERATED_BODY()
public:
	UAgentTeamsPresetFactory();
	virtual FText GetDisplayName() const override; 
	virtual uint32 GetMenuCategories() const override; 
	virtual const TArray<FText>& GetMenuCategorySubMenus() const override;
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
private:
	TArray<FText> Subcategories;
};

class FAgentTeamsPresetAssetTypeActions final : public FAssetTypeActions_Base 
{
	virtual FText GetName() const override; 
	virtual uint32 GetCategories() override; 
	virtual UClass* GetSupportedClass() const override; 
	virtual FColor GetTypeColor() const override;
};