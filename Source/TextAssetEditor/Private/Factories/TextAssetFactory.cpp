// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TextAssetFactory.h"

#include "Containers/UnrealString.h"
#include "TextAsset.h"
#include "Misc/FileHelper.h"


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

/* This is the old API (only for demonstration purposes)
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
}*/


UObject* UTextAssetFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UTextAsset* TextAsset = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *Filename))
	{
		TextAsset = NewObject<UTextAsset>(InParent, InClass, InName, Flags);
		TextAsset->Text = FText::FromString(TextString);
	}

	bOutOperationCanceled = false;

	return TextAsset;
}
