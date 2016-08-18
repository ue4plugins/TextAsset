// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

using UnrealBuildTool;

public class TextAssetEditor : ModuleRules
{
	public TextAssetEditor(TargetInfo Target)
	{
		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				"AssetTools",
				"MainFrame",
//				"WorkspaceMenuStructure",
			}
		);

		PrivateIncludePaths.AddRange(
			new string[] {
				"TextAssetEditor/Private",
				"TextAssetEditor/Private/AssetTools",
				"TextAssetEditor/Private/Factories",
				"TextAssetEditor/Private/Styles",
				"TextAssetEditor/Private/Widgets",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"ContentBrowser",
				"Core",
				"CoreUObject",
                "DesktopWidgets",
				"EditorStyle",
				"Engine",
				"InputCore",
                "Projects",
				"Slate",
				"SlateCore",
                "TextAsset",
				"UnrealEd",
			}
		);

		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"AssetTools",
				"UnrealEd",
//				"WorkspaceMenuStructure",
			}
		);
	}
}
