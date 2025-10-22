// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"




class FCableComponentBisPlugin : public IModuleInterface
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FCableComponentBisPlugin, CableComponent )



void FCableComponentBisPlugin::StartupModule()
{
	
}


void FCableComponentBisPlugin::ShutdownModule()
{
	
}



