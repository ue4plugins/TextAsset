// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TextAssetPCH.h"
#include "ModuleInterface.h"
#include "TextAsset.h"


/**
 * Implements the TextAsset module.
 */
class FTextAssetModule
	: public IModuleInterface
{
public:

	//~ IModuleInterface interface

	virtual void StartupModule() override { }
	virtual void ShutdownModule() override { }

	virtual bool SupportsDynamicReloading() override
	{
		return true;
	}
};


IMPLEMENT_MODULE(FTextAssetModule, TextAsset);
