// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "STextAssetEditor.h"

#include "Fonts/SlateFontInfo.h"
#include "Internationalization/Text.h"
#include "TextAsset.h"
#include "UObject/Class.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"

#include "TextAssetEditorSettings.h"


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

	auto Settings = GetDefault<UTextAssetEditorSettings>();

	ChildSlot
	[
		SNew(SVerticalBox)

		+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			[
				SAssignNew(EditableTextBox, SMultiLineEditableTextBox)
					.BackgroundColor((Settings != nullptr) ? Settings->BackgroundColor : FLinearColor::White)
					.Font((Settings != nullptr) ? Settings->Font : FSlateFontInfo())
					.ForegroundColor((Settings != nullptr) ? Settings->ForegroundColor : FLinearColor::Black)
					.Margin((Settings != nullptr) ? Settings->Margin : 4.0f)
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
