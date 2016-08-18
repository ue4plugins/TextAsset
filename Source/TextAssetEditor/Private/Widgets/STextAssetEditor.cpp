// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

#include "TextAssetEditorPrivatePCH.h"
#include "STextAssetEditor.h"


#define LOCTEXT_NAMESPACE "STextAssetEditor"


/* STextAssetEditor interface
 *****************************************************************************/

STextAssetEditor::~STextAssetEditor()
{
	FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
}


void STextAssetEditor::Construct(const FArguments& InArgs, UTextAsset* InTextAsset, const TSharedRef<ISlateStyle>& InStyle)
{
	TextAsset = InTextAsset;

	ChildSlot
	[
		SNew(SVerticalBox)

		+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			[
				SAssignNew(EditableTextBox, SMultiLineEditableTextBox)
					.OnTextChanged(this, &STextAssetEditor::HandleEditableTextBoxTextChanged)
					.OnTextCommitted(this, &STextAssetEditor::HandleEditableTextBoxTextCommitted)
					.Text(TextAsset->Text)
			]
	];

	FCoreUObjectDelegates::OnObjectPropertyChanged.AddSP(this, &STextAssetEditor::HandleTextAssetPropertyChanged);
}


/* STextAssetEditor callbacks
 *****************************************************************************/

void STextAssetEditor::HandleEditableTextBoxTextChanged(const FText& NewText)
{
	TextAsset->MarkPackageDirty();
}


void STextAssetEditor::HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType)
{
	TextAsset->Text = EditableTextBox->GetText();
}


void STextAssetEditor::HandleTextAssetPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent)
{
	if (Object == TextAsset)
	{
		EditableTextBox->SetText(TextAsset->Text);
	}
}


#undef LOCTEXT_NAMESPACE
