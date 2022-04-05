// Fill out your copyright notice in the Description page of Project Settings.


#include "Assets/AgentTeamsPreset.h"

FGenericTeamId UAgentTeamsPreset::GetIDFromTeam(UAgentTeam* InTeam) const
{
	int i = 0;
	for(auto It : Teams)
	{
		if(It == InTeam)
			return FGenericTeamId(i);
		i++;
	}
	return FGenericTeamId::NoTeam;
}

UAgentTeam* UAgentTeamsPreset::GetTeamFromID(FGenericTeamId InId) const
{
	if(InId < Teams.Num())
		return Teams.Array()[InId];
	return DefaultTeam;
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
	if(DefaultTeam == nullptr)
	{
		Return = EDataValidationResult::Invalid;
		ValidationErrors.Add(FText::FromString(TEXT("UAgentTeamsPreset DefaultTeam cannot be nullptr")));
	}

	
	return Return;
}
