// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class YangGeunsoo_Test : ModuleRules
{
	public YangGeunsoo_Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
