// Fill out your copyright notice in the Description page of Project Settings.


#include "Interfaces/TeamAssignable.h"
#include "Assets/AgentTeam.h"

// Add default functionality here for any ITeamAssignable functions that are not pure virtual.
bool ITeamAssignable::AssignTeam_Implementation(UAgentTeam* InTeam)
{
	return false;
}

UAgentTeam* ITeamAssignable::GetAssignedTeam_Implementation()
{
	return GetMutableDefault<UAgentTeam>();
}
