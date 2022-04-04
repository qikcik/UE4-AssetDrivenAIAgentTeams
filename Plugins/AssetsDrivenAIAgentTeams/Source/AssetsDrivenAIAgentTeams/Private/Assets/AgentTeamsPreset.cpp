// Fill out your copyright notice in the Description page of Project Settings.


#include "Assets/AgentTeamsPreset.h"

uint8 UAgentTeamsPreset::GetIDFromTeam(UAgentTeam* InTeam) const
{
	return 0;
}

UAgentTeam* UAgentTeamsPreset::GetTeamFromID(uint8 InTeam) const
{
	return nullptr;
}

UAgentTeam* UAgentTeamsPreset::GetDefaultTeam() const 
{
	return DefaultTeam;
}

const TSet<UAgentTeam*>& UAgentTeamsPreset::GetTeams() const
{
	return Teams;
}

EDataValidationResult UAgentTeamsPreset::IsDataValid(TArray<FText>& ValidationErrors)
{
	auto Return = Super::IsDataValid(ValidationErrors);
	if(Teams.Num() >= 255)
	{
		Return = EDataValidationResult::Invalid;
		ValidationErrors.Add(FText::FromString(TEXT("UAgentTeamsPreset Cannot have more than 254 Teams")));
	}
	return Return;
}
