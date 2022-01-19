// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AssetTypeActions_Base.h"
#include "Templates/SharedPointer.h"

class ISlateStyle;


/**
 * Implements an action for UTextAsset assets.
 */
class FTextAssetActions
	: public FAssetTypeActions_Base {
public:
	/**
	 * Creates and initializes a new instance.
	 *
	 * @param InStyle The style set to use for asset editor toolkits.
	 */
	FTextAssetActions(const TSharedRef<ISlateStyle>& InStyle);

	//~ FAssetTypeActions_Base overrides

	virtual bool CanFilter() override;

	/**
	 * Get the actions for the passed in InObjects and display them within the MenuBuilder
	 * @param InObjects Reference to objects that have actions to display
	 * @param MenuBuilder Menu that will show the available actions
	 */
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

	/**
	 * Where in the content browser content menu this asset will show up, using the EAssetTypeCategories enum
	 * @return Category that the asset belongs to
	 */
	virtual uint32 GetCategories() override;

	/**
	 * Get the name of the asset, will be shown in the thumbnail within the editor
	 * @return FText for the name of the asset
	 */
	virtual FText GetName() const override;

	/**
	 * Tells the editor which class the asset is. <br />
	 * <b>This must be implemented so the editor knows which class is to be used</b>
	 * @return UClass that is supported
	 */
	virtual UClass* GetSupportedClass() const override;

	/**
	 * Get the color to be used in the thumbnail for the asset
	 * @return FColor to be used
	 */
	virtual FColor GetTypeColor() const override;

	/**
	 * Whether or not the passed in InObjects should display any context menu action
	 * @param InObjects Reference to objects that will be checked for actions
	 * @return If any of the InObjects have actions available
	 */
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override;

	/**
	 * Called whenever a user wishes to open an asset(or assets) for editing
	 * @param InObjects Assets that the user is trying to open
	 * @param EditWithinLevelEditor Pointer to the toolkit host, defaulted to exist.
	 *			Checked within the function to determine which type of asset editor to open
	 */
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

private:
	/** Pointer to the style set to use for toolkits. */
	TSharedRef<ISlateStyle> Style;
};
