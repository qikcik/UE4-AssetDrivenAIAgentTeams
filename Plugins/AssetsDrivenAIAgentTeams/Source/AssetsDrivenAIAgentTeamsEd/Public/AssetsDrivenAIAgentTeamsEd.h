// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "AssetTypeCategories.h"
#include "IAssetTypeActions.h"

class FAssetsDrivenAIAgentTeamsEdModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static EAssetTypeCategories::Type GetMenuCategory();

private:
	static EAssetTypeCategories::Type MenuCategory;
	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
};
