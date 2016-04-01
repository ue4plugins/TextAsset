// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

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

	/** Holds the stored text. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="TextAsset")
	FText Text;
};
