// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TextAssetEditorPrivatePCH.h"
#include "TextAssetFactoryNew.h"


/* UTextAssetFactoryNew structors
 *****************************************************************************/

UTextAssetFactoryNew::UTextAssetFactoryNew(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UTextAssetFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UTextAsset>(InParent, InClass, InName, Flags);
}


bool UTextAssetFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}
