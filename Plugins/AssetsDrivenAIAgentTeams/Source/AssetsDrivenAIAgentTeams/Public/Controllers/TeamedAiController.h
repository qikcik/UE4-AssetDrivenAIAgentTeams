﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Interfaces/TeamAssignable.h"
#include "UObject/Object.h"
#include "TeamedAiController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType,meta=(ToolTip="AiController with support for AssetsDrivenAiAgenTeams"))
class ASSETSDRIVENAIAGENTTEAMS_API ATeamedAiController : public AAIController, public ITeamAssignable
{
	GENERATED_BODY()
public:

protected:
	virtual bool AssignTeam_Implementation(UAgentTeam* InTeam) override;
	virtual UAgentTeam* GetAssignedTeam_Implementation() override;

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UAgentTeam* Team = GetMutableDefault<UAgentTeam>();
};