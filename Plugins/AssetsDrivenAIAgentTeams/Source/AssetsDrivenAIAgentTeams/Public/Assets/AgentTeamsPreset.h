// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "UObject/Object.h"
#include "AgentTeamsPreset.generated.h"

class UAgentTeam;
UCLASS()
class ASSETSDRIVENAIAGENTTEAMS_API UAgentTeamsPreset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure,Category="AgentTeamsPreset")
	FGenericTeamId GetIDFromTeam(UAgentTeam* InTeam) const;

	UFUNCTION(BlueprintPure,Category="AgentTeamsPreset")
	UAgentTeam* GetTeamFromID(FGenericTeamId InId) const;
	
	UFUNCTION(BlueprintPure,Category="AgentTeamsPreset")
	UAgentTeam* GetDefaultTeam() const;

	UFUNCTION(BlueprintPure,Category="AgentTeamsPreset",meta=(ToolTip="MaxAmount is 254"))
	UPARAM(ref) const TSet<UAgentTeam*>& GetTeams() const;

#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(TArray<FText>& ValidationErrors) override;
#endif
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(ToolTip="used when not found in teams array"))
	UAgentTeam* DefaultTeam;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,EditFixedSize=254)
	TSet<UAgentTeam*> Teams;
};
