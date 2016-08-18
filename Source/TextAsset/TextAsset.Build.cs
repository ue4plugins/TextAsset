// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class TextAsset : ModuleRules
	{
		public TextAsset(TargetInfo Target)
		{
            PublicDependencyModuleNames.AddRange(
                new string[] {
					"Core",
					"CoreUObject",
                }
            );

			PrivateIncludePaths.AddRange(
				new string[] {
					"Runtime/TextAsset/Private",
				}
			);
		}
	}
}
