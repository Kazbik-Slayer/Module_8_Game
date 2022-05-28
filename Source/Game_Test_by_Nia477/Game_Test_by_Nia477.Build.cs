// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Game_Test_by_Nia477 : ModuleRules
{
	public Game_Test_by_Nia477(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara" });
    }
}
