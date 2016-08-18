// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

#include "TextAssetEditorPrivatePCH.h"
#include "STextAssetEditor.h"
#include "TextAssetEditorToolkit.h"


#define LOCTEXT_NAMESPACE "FTextAssetEditorToolkit"

DEFINE_LOG_CATEGORY_STATIC(LogTextAssetEditor, Log, All);


/* Local constants
 *****************************************************************************/

static const FName TextAssetEditorAppIdentifier("TextAssetEditorApp");
static const FName TextEditorTabId("TextEditor");


/* FTextAssetEditorToolkit structors
 *****************************************************************************/

FTextAssetEditorToolkit::FTextAssetEditorToolkit(const TSharedRef<ISlateStyle>& InStyle)
	: TextAsset(nullptr)
	, Style(InStyle)
{ }


FTextAssetEditorToolkit::~FTextAssetEditorToolkit()
{
	FReimportManager::Instance()->OnPreReimport().RemoveAll(this);
	FReimportManager::Instance()->OnPostReimport().RemoveAll(this);

	GEditor->UnregisterForUndo(this);
}


/* FTextAssetEditorToolkit interface
 *****************************************************************************/

void FTextAssetEditorToolkit::Initialize(UTextAsset* InTextAsset, const EToolkitMode::Type InMode, const TSharedPtr<class IToolkitHost>& InToolkitHost)
{
	TextAsset = InTextAsset;

	// Support undo/redo
	TextAsset->SetFlags(RF_Transactional);
	GEditor->RegisterForUndo(this);

	// create tab layout
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_TextAssetEditor")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
				->SetOrientation(Orient_Horizontal)
				->Split
				(
					FTabManager::NewSplitter()
						->SetOrientation(Orient_Vertical)
						->SetSizeCoefficient(0.66f)
						->Split
						(
							FTabManager::NewStack()
								->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
								->SetHideTabWell(true)
								->SetSizeCoefficient(0.1f)
								
						)
						->Split
						(
							FTabManager::NewStack()
								->AddTab(TextEditorTabId, ETabState::OpenedTab)
								->SetHideTabWell(true)
								->SetSizeCoefficient(0.9f)
						)
				)
		);

	FAssetEditorToolkit::InitAssetEditor(
		InMode,
		InToolkitHost,
		TextAssetEditorAppIdentifier,
		Layout,
		true /*bCreateDefaultStandaloneMenu*/,
		true /*bCreateDefaultToolbar*/,
		InTextAsset
	);

	RegenerateMenusAndToolbars();
}


/* FAssetEditorToolkit interface
 *****************************************************************************/

FString FTextAssetEditorToolkit::GetDocumentationLink() const
{
	return FString(TEXT("https://github.com/ue4plugins/TextAsset"));
}


void FTextAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_TextAssetEditor", "Text Asset Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(TextEditorTabId, FOnSpawnTab::CreateSP(this, &FTextAssetEditorToolkit::HandleTabManagerSpawnTab, TextEditorTabId))
		.SetDisplayName(LOCTEXT("TextEditorTabName", "Text Editor"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}


void FTextAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(TextEditorTabId);
}


/* IToolkit interface
 *****************************************************************************/

FText FTextAssetEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Text Asset Editor");
}


FName FTextAssetEditorToolkit::GetToolkitFName() const
{
	return FName("TextAssetEditor");
}


FLinearColor FTextAssetEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}


FString FTextAssetEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "TextAsset ").ToString();
}


/* FGCObject interface
 *****************************************************************************/

void FTextAssetEditorToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(TextAsset);
}


/* FEditorUndoClient interface
*****************************************************************************/

void FTextAssetEditorToolkit::PostUndo(bool bSuccess)
{ }


void FTextAssetEditorToolkit::PostRedo(bool bSuccess)
{
	PostUndo(bSuccess);
}


/* FTextAssetEditorToolkit callbacks
 *****************************************************************************/

TSharedRef<SDockTab> FTextAssetEditorToolkit::HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier)
{
	TSharedPtr<SWidget> TabWidget = SNullWidget::NullWidget;

	if (TabIdentifier == TextEditorTabId)
	{
		TabWidget = SNew(STextAssetEditor, TextAsset, Style);
	}

	return SNew(SDockTab)
		.TabRole(ETabRole::PanelTab)
		[
			TabWidget.ToSharedRef()
		];
}


#undef LOCTEXT_NAMESPACE
