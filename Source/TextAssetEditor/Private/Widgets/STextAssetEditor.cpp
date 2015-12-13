// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TextAssetEditorPrivatePCH.h"
#include "SMultiLineEditableTextBox.h"


#define LOCTEXT_NAMESPACE "STextAssetEditor"


/* STextAssetEditor interface
 *****************************************************************************/

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


#undef LOCTEXT_NAMESPACE
