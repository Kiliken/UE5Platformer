// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5Platformer : ModuleRules
{
	public UE5Platformer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ImGui" });
	}
}
