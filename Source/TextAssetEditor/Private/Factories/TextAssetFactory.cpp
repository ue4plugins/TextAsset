// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TextAssetEditorPrivatePCH.h"
#include "TextAssetFactory.h"


/* UTextAssetFactory structors
 *****************************************************************************/

UTextAssetFactory::UTextAssetFactory( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("txt;")) + NSLOCTEXT("UTextAssetFactory", "FormatTxt", "Text File").ToString());
	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UTextAssetFactory::FactoryCreateBinary(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	UTextAsset* TextAsset = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *CurrentFilename))
	{
		TextAsset = NewObject<UTextAsset>(InParent, Class, Name, Flags);
		TextAsset->Text = FText::FromString(TextString);
	}

	return TextAsset;
}
