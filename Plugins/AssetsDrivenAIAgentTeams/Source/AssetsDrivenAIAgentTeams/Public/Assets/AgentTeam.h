// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "UObject/Object.h"
#include "AgentTeam.generated.h"

class UAgentTeamExtendInfo;
UCLASS(BlueprintType,meta=(ToolTip="Represent team, that can be assigned to specific AI(Player) Controller"))
class ASSETSDRIVENAIAGENTTEAMS_API UAgentTeam : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="AgentTeam")
	TEnumAsByte<ETeamAttitude::Type> GetAttitudeToward(const UAgentTeam* InAgentTeam );



protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="AgentTeam",meta=(ToolTip="Atiltude toward agent team that isn't specified"))
	TEnumAsByte<ETeamAttitude::Type> DefaultAttitudeToStrangers {ETeamAttitude::Type::Neutral};

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="AgentTeam",meta=(ToolTip="team attlitude [value] towards agent team [key]"))
	TMap<TSoftObjectPtr<UAgentTeam>,TEnumAsByte<ETeamAttitude::Type>> AttitudeTowards;

};
