// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateSequence.h"
#include "AssetToolsModule.h"

UObject* UGenerateSequence::CreateAsset(FString AssetPath, UClass* AssetClass, UFactory* AssetFactory, bool& bOutSuccess, FString& OutInfoMessage)
{
	// Get the asset tools module
	IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

	// Find the right factory
	UFactory* Factory = AssetFactory;
	if (Factory == nullptr)
	{
		for (UFactory* Fac : AssetTools.GetNewAssetFactories())
		{
			if (Fac->SupportedClass == AssetClass)
			{
				Factory = Fac;
				break;
			}
		}
		if (Factory == nullptr)
		{
			bOutSuccess = false;
			OutInfoMessage = FString::Printf(TEXT("Create Asset Failed - Was not able to find factory for AssetClass. '%s'"), *AssetPath);
			return nullptr;
		}
	}

	// Can the factory create desired asset?
	if (Factory->SupportedClass != AssetClass)
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Create Asset Failed - Factory cannot create desired AssetClass. '%s'"), *AssetPath);
		return nullptr;
	}

	// Create asset
	UObject* Asset = AssetTools.CreateAsset(FPaths::GetBaseFilename(AssetPath), FPaths::GetPath(AssetPath), AssetClass, Factory);

	if (Asset == nullptr)
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Create Asset Failed - Either the path is invalid or the asset already exists. '%s'"), *AssetPath);
		return nullptr;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Create Asset Succeeded - '%s'"), *AssetPath);
	return Asset;
}

FGuid UGenerateSequence::CreateLevelSequence()
{
	return FGuid();
}

ULevelSequence* UGenerateSequence::CreateLevelSequenceAsset(FString AssetPath, bool& bOutSuccess, FString& OutInfoMessage)
{
	UObject* Asset = CreateAsset(AssetPath, ULevelSequence::StaticClass(), nullptr, bOutSuccess, OutInfoMessage);
	return Cast<ULevelSequence>(Asset);
}

FGuid UGenerateSequence::AddActorIntoLevelSequence()
{
	return FGuid();
}

FGuid UGenerateSequence::CreateCamera()
{
	return FGuid();
}

FGuid UGenerateSequence::AddCameraIntoLevelSequence()
{
	return FGuid();
}

FGuid UGenerateSequence::SetCameraTransform()
{
	return FGuid();
}
