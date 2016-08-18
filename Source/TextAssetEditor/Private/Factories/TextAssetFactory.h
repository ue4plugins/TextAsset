// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"
#include "TextAssetFactory.generated.h"


/**
 * Implements a factory for UTextAsset objects.
 */
UCLASS(hidecategories=Object)
class UTextAssetFactory
	: public UFactory
{
	GENERATED_UCLASS_BODY()

public:

	// UFactory Interface

	virtual UObject* FactoryCreateBinary(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn) override;
};
