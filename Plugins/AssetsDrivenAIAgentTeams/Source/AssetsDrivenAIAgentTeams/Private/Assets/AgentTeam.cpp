// Fill out your copyright notice in the Description page of Project Settings.


#include "Assets/AgentTeam.h"

#include "Assets/AgentTeamExtendInfo.h"

TEnumAsByte<ETeamAttitude::Type> UAgentTeam::GetAttitudeToward(const UAgentTeam* InAgentTeam)
{
	if(AttitudeTowards.Contains(InAgentTeam))
		return AttitudeTowards[InAgentTeam];
	return DefaultAttitudeToStrangers;
}

UAgentTeamExtendInfo* UAgentTeam::GetExtendInfo(TSubclassOf<UAgentTeamExtendInfo> InClass)
{
	for(auto It : ExtendInfos)
	{
		if(!It) continue;
		
		if(It->GetClass() == InClass)
			return It;
	}
	auto* FirstRequested = NewObject<UAgentTeamExtendInfo>(this,InClass);
	ExtendInfos.Add(FirstRequested);
	return FirstRequested;
}

EDataValidationResult UAgentTeam::IsDataValid(TArray<FText>& ValidationErrors)
{
	auto Return = Super::IsDataValid(ValidationErrors);
	TSet<UClass*> Classes;
	for(auto It : ExtendInfos)
	{
		if(!It) continue;
		
		if(Classes.Contains(It->GetClass()))
		{
			Return = EDataValidationResult::Invalid;
			FString String = It->GetClass()->GetName();
			String  = String.Append(" - duplicated ExtendInfo");
			ValidationErrors.Add(FText::FromString(String));
		}
		Classes.Add(It->GetClass());
	}
	return Return;
	
}
