// Fill out your copyright notice in the Description page of Project Settings.


#include "Helpers/AgentTeamAssetActionUtlity.h"

#include "EditorUtilitySubsystem.h"
#include "EditorUtilityWidget.h"

UEditorUtilityWidget* UAgentTeamAssetActionUtlity::ShowEditorUtilityWidget()
{
	UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
	return EditorUtilitySubsystem->SpawnAndRegisterTab(EditorUtilityWidget);
}
