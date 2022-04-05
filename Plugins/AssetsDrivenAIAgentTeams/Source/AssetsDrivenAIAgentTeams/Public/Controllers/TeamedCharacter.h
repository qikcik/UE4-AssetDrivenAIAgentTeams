// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/Character.h"
#include "Interfaces/TeamAssignable.h"
#include "UObject/Object.h"
#include "TeamedCharacter.generated.h"

class UAgentTeam;
/**
 * 
 */
UCLASS()
class ASSETSDRIVENAIAGENTTEAMS_API ATeamedCharacter : public ACharacter, public IGenericTeamAgentInterface, public ITeamAssignable
{
	GENERATED_BODY()
	
protected:
	virtual bool AssignTeam_Implementation(UAgentTeam* InTeam) override;
	virtual UAgentTeam* GetAssignedTeam_Implementation() override;

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UAgentTeam* Team = GetMutableDefault<UAgentTeam>();
};
