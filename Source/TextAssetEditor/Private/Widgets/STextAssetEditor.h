// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

#pragma once


/**
 * Implements the UTextAsset asset editor widget.
 */
class STextAssetEditor
	: public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(STextAssetEditor) { }
	SLATE_END_ARGS()

public:

	/** Virtual destructor. */
	virtual ~STextAssetEditor();

	/**
	 * Construct this widget
	 *
	 * @param InArgs The declaration data for this widget.
	 * @param InTextAsset The UTextAsset asset to edit.
	 * @param InStyleSet The style set to use.
	 */
	void Construct(const FArguments& InArgs, UTextAsset* InTextAsset, const TSharedRef<ISlateStyle>& InStyle);

private:

	/** Callback for text changes in the editable text box. */
	void HandleEditableTextBoxTextChanged(const FText& NewText);

	/** Callback for committed text in the editable text box. */
	void HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType);

	/** Callback for property changes in the text asset. */
	void HandleTextAssetPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent);

private:

	/** Holds the editable text box widget. */
	TSharedPtr<SMultiLineEditableTextBox> EditableTextBox;

	/** Pointer to the text asset that is being edited. */
	UTextAsset* TextAsset;
};
