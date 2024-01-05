// Copyright (C) Kimi Zhong - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LevelSequence.h"
#include "MovieScene.h"
#include "Factories/Factory.h"
#include "Factories/WorldFactory.h"

#include "GenerateSequence.generated.h"

class UFactory;

/**
 * 
 */
UCLASS()
class AUTOSEQUENCER_API UGenerateSequence : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Level sequence related
	/** 
	 * Create an asset.
	 * @param AssetPath				The path to create the asset: "/Game/Folder/MyAsset"	
	 * @param AssetClass			The class of asset to create
	 * @param AssetFactory			Nullable. The factory to use to create the asset
	 * @param bOutSuccess			Whether the action was a success or not
	 * @param OutInfoMessage		More info to log
	 * return The created asset
	 */
	UFUNCTION(BlueprintCallable, Category = "AutoSequencer")
		static UObject* CreateAsset(FString AssetPath, UClass* AssetClass, UFactory* AssetFactory, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "AutoSequencer")
		static FGuid CreateLevelSequence();

	UFUNCTION(BlueprintCallable, Category = "AutoSequencer")
		static ULevelSequence* CreateLevelSequenceAsset(FString AssetPath, bool& bOutSuccess, FString& OutInfoMessage);

	// Character and Animation related
	UFUNCTION(BlueprintCallable, Category = "AutoSequencer")
		static FGuid AddActorIntoLevelSequence();



	// Camera related
	UFUNCTION(BlueprintCallable, Category = "AutoSequencer")
		static FGuid CreateCamera();

	UFUNCTION(BlueprintCallable, Category = "AutoSequencer")
		static FGuid AddCameraIntoLevelSequence();

	UFUNCTION(BlueprintCallable, Category = "AutoSequencer")
		static FGuid SetCameraTransform();
};

