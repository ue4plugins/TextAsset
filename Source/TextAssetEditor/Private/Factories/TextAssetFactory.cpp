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
	    TextAsset->AssetImportData->AddFileName(Filename, 0);
	}

	bOutOperationCanceled = false;

	return TextAsset;
}



bool UTextAssetFactory::CanReimport(UObject * Obj, TArray<FString>& OutFilenames)
{
    UTextAsset* pTextAsset = Cast<UTextAsset>(Obj);

    if (pTextAsset)
    {
        pTextAsset->AssetImportData->ExtractFilenames(OutFilenames);
        return true;
    }

    return false;
}

void UTextAssetFactory::SetReimportPaths(UObject * Obj, const TArray<FString>& NewReimportPaths)
{
    UTextAsset* pTextAsset = Cast<UTextAsset>(Obj);

    //TextAsset can only own one pertaining file.
    if (pTextAsset && ensure(NewReimportPaths.Num() == 1))
    {
        pTextAsset->AssetImportData->UpdateFilenameOnly(NewReimportPaths[0]);
    }
}

EReimportResult::Type UTextAssetFactory::Reimport(UObject * Obj)
{
    //Actually do reimport;
    if (!Obj || !Obj->IsA(UTextAsset::StaticClass()))
    {
        return EReimportResult::Failed;
    }

    UTextAsset* pTextAsset = Cast<UTextAsset>(Obj);
    const FString ResolvedSourceFilePath = pTextAsset->AssetImportData->GetFirstFilename();

    if (!ResolvedSourceFilePath.Len())
    {
        return EReimportResult::Failed;
    }

    FString NewText;

    if (FFileHelper::LoadFileToString(NewText, *ResolvedSourceFilePath))
    {
        pTextAsset->Text = FText::FromString(NewText);
        pTextAsset->Modify();
        return EReimportResult::Succeeded;
    }

    return EReimportResult::Failed;
}

