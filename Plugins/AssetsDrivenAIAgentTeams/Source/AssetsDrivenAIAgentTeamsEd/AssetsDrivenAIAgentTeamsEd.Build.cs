// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AssetsDrivenAIAgentTeamsEd : ModuleRules
{
	public AssetsDrivenAIAgentTeamsEd(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "Source/Editor/Blutility/Private"
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"AssetsDrivenAIAgentTeams",
				"Engine",
				"CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "ToolMenus",
                "EditorStyle",
                "Blutility",
                "UMGEditor",
                "UMG",
                "PropertyEditor",
                "EditorScriptingUtilities",
                "UnrealEd",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{

				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
