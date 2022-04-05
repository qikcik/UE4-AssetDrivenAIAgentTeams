// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TeamedCharacter.h"

#include "Assets/AgentTeam.h"

bool ATeamedCharacter::AssignTeam_Implementation(UAgentTeam* InTeam)
{
	if(!ensureMsgf(InTeam,TEXT("In team cannot be nullptr")))
	{
		Team = GetMutableDefault<UAgentTeam>();
		return false;
	}
	Team = InTeam;
	return true;
}

UAgentTeam* ATeamedCharacter::GetAssignedTeam_Implementation()
{
	return Team;
}

ETeamAttitude::Type ATeamedCharacter::GetTeamAttitudeTowards(const AActor& Other) const
{
	if( Other.GetClass()->ImplementsInterface(UTeamAssignable::StaticClass()))
	{
		const auto* OtherTeam = ITeamAssignable::Execute_GetAssignedTeam(const_cast<AActor*>(&Other));
		return Team->GetAttitudeToward(OtherTeam);
	}
	return Team->GetAttitudeToward(nullptr);
}
 