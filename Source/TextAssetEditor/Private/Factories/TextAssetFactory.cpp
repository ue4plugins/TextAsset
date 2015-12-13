// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TextAssetEditorPrivatePCH.h"
#include "TextAssetFactory.h"


/* UTextAssetFactory structors
 *****************************************************************************/

UTextAssetFactory::UTextAssetFactory( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UTextAssetFactory::FactoryCreateBinary(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	return NewObject<UTextAsset>(InParent, Class, Name, Flags);
}
