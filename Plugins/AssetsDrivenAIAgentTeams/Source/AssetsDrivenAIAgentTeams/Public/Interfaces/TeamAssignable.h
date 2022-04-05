// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TeamAssignable.generated.h"

class UAgentTeam;
// This class does not need to be modified.
UINTERFACE(BlueprintType, meta=(ToolTip="use to assign team, get assigned team"))
class ASSETSDRIVENAIAGENTTEAMS_API UTeamAssignable : public UInterface
{
	GENERATED_BODY()
};


class ASSETSDRIVENAIAGENTTEAMS_API ITeamAssignable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	bool AssignTeam(UAgentTeam* InTeam);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	UAgentTeam* GetAssignedTeam();

protected:
	virtual bool AssignTeam_Implementation(UAgentTeam* InTeam);
	virtual UAgentTeam* GetAssignedTeam_Implementation();
};
