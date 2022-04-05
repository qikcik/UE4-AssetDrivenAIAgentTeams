// Fill out your copyright notice in the Description page of Project Settings.


#include "Interfaces/GameStateTeamsPresetOverridable.h"


// Add default functionality here for any IGameStateTeamsPresetOverridable functions that are not pure virtual.
UAgentTeamsPreset* IGameStateTeamsPresetOverridable::GetOverrideTeamsPreset_Implementation()
{
	return nullptr;
}
