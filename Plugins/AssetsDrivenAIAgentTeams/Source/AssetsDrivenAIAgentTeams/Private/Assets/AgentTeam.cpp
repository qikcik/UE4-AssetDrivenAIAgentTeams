// Fill out your copyright notice in the Description page of Project Settings.


#include "Assets/AgentTeam.h"


TEnumAsByte<ETeamAttitude::Type> UAgentTeam::GetAttitudeToward(const UAgentTeam* InAgentTeam)
{
	if(AttitudeTowards.Contains(InAgentTeam))
		return AttitudeTowards[InAgentTeam];
	return DefaultAttitudeToStrangers;
}
