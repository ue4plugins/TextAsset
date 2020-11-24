// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Internationalization/Text.h"
#include "UObject/Object.h"
#include "EditorFramework/AssetImportData.h"
#include "UObject/ObjectMacros.h"

#include "TextAsset.generated.h"


/**
 * Implements an asset that can be used to store arbitrary text, such as notes
 * or documentation.
 */
UCLASS(BlueprintType, hidecategories=(Object))
class TEXTASSET_API UTextAsset
	: public UObject
{
	GENERATED_BODY()

public:

    
    virtual void PostInitProperties() override;

#if WITH_EDITORONLY_DATA

    virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override
    {
        if (AssetImportData)
        {
            OutTags.Add(FAssetRegistryTag(SourceFileTagName(), AssetImportData->GetSourceData().ToJson(), FAssetRegistryTag::TT_Hidden));
        }

        Super::GetAssetRegistryTags(OutTags);
    }
    
    UPROPERTY(VisibleAnywhere, Instanced, Category = ImportSettings)
    UAssetImportData* AssetImportData;
#endif
	/** Holds the stored text. */
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="TextAsset")
    FText Text;
};
