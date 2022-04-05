// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TeamedAiController.h"

#include "Assets/AgentTeam.h"

bool ATeamedAiController::AssignTeam_Implementation(UAgentTeam* InTeam)
{
	if(!ensureMsgf(InTeam,TEXT("In team cannot be nullptr")))
	{
		Team = GetMutableDefault<UAgentTeam>();
		return false;
	}
	Team = InTeam;
	return true;
}

UAgentTeam* ATeamedAiController::GetAssignedTeam_Implementation()
{
	return Team;
}

ETeamAttitude::Type ATeamedAiController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const auto* OtherTeam = ITeamAssignable::Execute_GetAssignedTeam(const_cast<AActor*>(&Other));
	return Team->GetAttitudeToward(OtherTeam);
}
 