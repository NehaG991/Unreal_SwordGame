// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_Sword : ModuleRules
{
	public UE_Sword(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
