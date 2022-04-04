// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilitySubsystem.h"
#include "AssetActionUtility.h"
#include "AgentTeamAssetActionUtlity.generated.h"


class UEditorUtilityWidget;
class UEditorUtilityWidgetBlueprint;

UCLASS()
class ASSETSDRIVENAIAGENTTEAMSED_API UAgentTeamAssetActionUtlity : public UAssetActionUtility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	UEditorUtilityWidget* ShowEditorUtilityWidget();
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UEditorUtilityWidgetBlueprint* EditorUtilityWidget = nullptr;
};
