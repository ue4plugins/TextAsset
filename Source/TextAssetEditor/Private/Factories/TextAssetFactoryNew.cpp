// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TextAssetFactoryNew.h"

#include "TextAsset.h"


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
