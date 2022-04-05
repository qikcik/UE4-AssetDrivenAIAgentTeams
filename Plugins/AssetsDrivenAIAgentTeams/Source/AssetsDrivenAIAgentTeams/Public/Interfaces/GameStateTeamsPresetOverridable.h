// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameStateTeamsPresetOverridable.generated.h"

class UAgentTeamsPreset;
// This class does not need to be modified.
UINTERFACE(BlueprintType, meta = (DisplayName="implement on gameState to override default preset"))
class ASSETSDRIVENAIAGENTTEAMS_API UGameStateTeamsPresetOverridable : public UInterface
{
	GENERATED_BODY()
};


class ASSETSDRIVENAIAGENTTEAMS_API IGameStateTeamsPresetOverridable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UAgentTeamsPreset* GetOverrideTeamsPreset();

protected:
	virtual UAgentTeamsPreset* GetOverrideTeamsPreset_Implementation();
};
