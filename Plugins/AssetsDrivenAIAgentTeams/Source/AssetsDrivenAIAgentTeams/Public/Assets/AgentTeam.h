// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "AgentTeam.generated.h"

UCLASS(BlueprintType,meta=(ToolTip="Represent team, that can be assigned to specific AI(Player) Controller"))
class ASSETSDRIVENAIAGENTTEAMS_API UAgentTeam : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="AgentTeam")
	FText GetDisplayName();

	
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="AgentTeam")
	FText DisplayName;
};
