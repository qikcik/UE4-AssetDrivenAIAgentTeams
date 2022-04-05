// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "Interfaces/TeamAssignable.h"
#include "UObject/Object.h"
#include "TeamedController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType,meta=(ToolTip="Controller with support for AssetsDrivenAiAgenTeams"))
class ASSETSDRIVENAIAGENTTEAMS_API ATeamedController : public AController, public IGenericTeamAgentInterface, public ITeamAssignable
{
	GENERATED_BODY()
	
protected:
	virtual bool AssignTeam_Implementation(UAgentTeam* InTeam) override;
	virtual UAgentTeam* GetAssignedTeam_Implementation() override;

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UAgentTeam* Team = GetMutableDefault<UAgentTeam>();
};
