// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TextAssetEditor : ModuleRules
{
	public TextAssetEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				"AssetTools",
				"MainFrame",
//				"WorkspaceMenuStructure",
			});

		PrivateIncludePaths.AddRange(
			new string[] {
				"TextAssetEditor/Private",
				"TextAssetEditor/Private/AssetTools",
				"TextAssetEditor/Private/Factories",
				"TextAssetEditor/Private/Shared",
				"TextAssetEditor/Private/Styles",
				"TextAssetEditor/Private/Toolkits",
				"TextAssetEditor/Private/Widgets",
			});

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
			});

		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"AssetTools",
				"UnrealEd",
//				"WorkspaceMenuStructure",
			});
	}
}
