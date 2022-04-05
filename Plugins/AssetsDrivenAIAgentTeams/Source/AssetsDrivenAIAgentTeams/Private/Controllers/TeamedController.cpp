// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TeamedController.h"

#include "Assets/AgentTeam.h"

bool ATeamedController::AssignTeam_Implementation(UAgentTeam* InTeam)
{
	if(!ensureMsgf(InTeam,TEXT("AgentTeam cannot be nullptr")))
	{
		Team = GetMutableDefault<UAgentTeam>();
		return false;
	}
	Team = InTeam;
	return true;
}

UAgentTeam* ATeamedController::GetAssignedTeam_Implementation()
{
	return Team;
}

ETeamAttitude::Type ATeamedController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const auto* OtherTeam = ITeamAssignable::Execute_GetAssignedTeam(const_cast<AActor*>(&Other));
	return Team->GetAttitudeToward(OtherTeam);
}
