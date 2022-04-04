// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assets/AgentTeam.h"
#include "UObject/Object.h"
#include "AgentTeamEdHelperBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ASSETSDRIVENAIAGENTTEAMSED_API UAgentTeamEdHelperBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static UAgentTeam* CreateAgentTeamWithDialog();

};
