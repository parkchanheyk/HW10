// Copyright Epic Games, Inc. All Rights Reserved.

#include "Temporary.h"

#define LOCTEXT_NAMESPACE "FTemporaryModule"

void FTemporaryModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Warning, TEXT("Temporary 플러그인이 로드되었습니다!"));
}

void FTemporaryModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTemporaryModule, Temporary)