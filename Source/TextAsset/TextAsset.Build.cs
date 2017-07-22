// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class TextAsset : ModuleRules
	{
		public TextAsset(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					"Runtime/TextAsset/Private",
				});
		}
	}
}
