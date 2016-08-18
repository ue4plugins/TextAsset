// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"
#include "TextAssetFactoryNew.generated.h"


/**
 * Implements a factory for UTextAsset objects.
 */
UCLASS(hidecategories=Object)
class UTextAssetFactoryNew
	: public UFactory
{
	GENERATED_UCLASS_BODY()

public:

	// UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};
