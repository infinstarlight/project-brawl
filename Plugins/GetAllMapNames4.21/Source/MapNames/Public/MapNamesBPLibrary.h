// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Misc/Paths.h"
#include "MapNamesBPLibrary.generated.h"

/*
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UMapNamesBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetAllMapNames", Keywords = "GAMNMaps"), Category = "MapNames")
	static FORCEINLINE TArray<FString> GetAllMapNames_p()
	{
		TArray<FString> MapFiles;

		IFileManager::Get().FindFilesRecursive(MapFiles, *FPaths::ProjectContentDir(), TEXT("*.umap"), true, false, false);
		//IFileManager::Get().FindFilesRecursive(MapFiles, *FPaths::ProjectPluginsDir(), TEXT("*.umap"), true, false, false);

		for (int32 i = 0; i < MapFiles.Num(); i++)
		{
			//replace the whole directory string with only the name of the map

			int32 lastSlashIndex = -1;
			if (MapFiles[i].FindLastChar('/', lastSlashIndex))
			{
				FString pureMapName;

				//length - 5 because of the ".umap" suffix
				for (int32 j = lastSlashIndex + 1; j < MapFiles[i].Len() - 5; j++)
				{
					pureMapName.AppendChar(MapFiles[i][j]);
				}

				MapFiles[i] = pureMapName;
			}
		}

		return MapFiles;
	}

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAllMapNames_Callable", Keywords = "GAMNMaps"), Category = "MapNames")
	static FORCEINLINE TArray<FString> GetAllMapNames()
	{
		TArray<FString> MapFiles;

		IFileManager::Get().FindFilesRecursive(MapFiles, *FPaths::ProjectContentDir(), TEXT("*.umap"), true, false, false);
		//IFileManager::Get().FindFilesRecursive(MapFiles, *FPaths::ProjectPluginsDir(), TEXT("*.umap"), true, false, false);

		for (int32 i = 0; i < MapFiles.Num(); i++)
		{
			//replace the whole directory string with only the name of the map

			int32 lastSlashIndex = -1;
			if (MapFiles[i].FindLastChar('/', lastSlashIndex))
			{
				FString pureMapName;

				//length - 5 because of the ".umap" suffix
				for (int32 j = lastSlashIndex + 1; j < MapFiles[i].Len() - 5; j++)
				{
					pureMapName.AppendChar(MapFiles[i][j]);
				}

				MapFiles[i] = pureMapName;
			}
		}

		return MapFiles;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Deathmatch Map Names", Keywords = "Get DM Maps"), Category = "Game Data")
	static FORCEINLINE TArray<FString> GetDMMapNames_p()
	{
		TArray<FString> DMMapFiles;

		IFileManager::Get().FindFilesRecursive(DMMapFiles, *FPaths::ProjectContentDir(), TEXT("DM_*.umap"), true, false, false);

		for (int32 i = 0; i < DMMapFiles.Num(); i++)
		{
			int32 lastSlashIndex = -1;
			if (DMMapFiles[i].FindLastChar('/', lastSlashIndex))
			{
				FString pureStoryMapName;

				for (int32 j = lastSlashIndex + 1; j < DMMapFiles[i].Len() - 5; j++)
				{
					pureStoryMapName.AppendChar(DMMapFiles[i][j]);
				}

				DMMapFiles[i] = pureStoryMapName;
			}
		}

		return DMMapFiles;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Team Deathmatch Map Names", Keywords = "Get TDM Maps"), Category = "Game Data")
	static FORCEINLINE TArray<FString> GetTDMMapNames_p()
	{
		TArray<FString> TDMMapFiles;

		IFileManager::Get().FindFilesRecursive(TDMMapFiles, *FPaths::ProjectContentDir(), TEXT("TDM_*.umap"), true, false, false);

		for (int32 i = 0; i < TDMMapFiles.Num(); i++)
		{
			int32 lastSlashIndex = -1;
			if (TDMMapFiles[i].FindLastChar('/', lastSlashIndex))
			{
				FString pureStoryMapName;

				for (int32 j = lastSlashIndex + 1; j < TDMMapFiles[i].Len() - 5; j++)
				{
					pureStoryMapName.AppendChar(TDMMapFiles[i][j]);
				}

				TDMMapFiles[i] = pureStoryMapName;
			}
		}

		return TDMMapFiles;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Conquest Map Names", Keywords = "Get CQ Maps"), Category = "Game Data")
	static FORCEINLINE TArray<FString> GetConquestMapNames_p()
	{
		TArray<FString> CQMapFiles;

		IFileManager::Get().FindFilesRecursive(CQMapFiles, *FPaths::ProjectContentDir(), TEXT("CQ_*.umap"), true, false, false);

		for (int32 i = 0; i < CQMapFiles.Num(); i++)
		{
			int32 lastSlashIndex = -1;
			if (CQMapFiles[i].FindLastChar('/', lastSlashIndex))
			{
				FString pureStoryMapName;

				for (int32 j = lastSlashIndex + 1; j < CQMapFiles[i].Len() - 5; j++)
				{
					pureStoryMapName.AppendChar(CQMapFiles[i][j]);
				}

				CQMapFiles[i] = pureStoryMapName;
			}
		}

		return CQMapFiles;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Rush Map Names", Keywords = "Get Rush Maps"), Category = "Game Data")
	static FORCEINLINE TArray<FString> GetRushMapNames_p()
	{
		TArray<FString> RMapFiles;

		IFileManager::Get().FindFilesRecursive(RMapFiles, *FPaths::ProjectContentDir(), TEXT("R_*.umap"), true, false, false);

		for (int32 i = 0; i < RMapFiles.Num(); i++)
		{
			int32 lastSlashIndex = -1;
			if (RMapFiles[i].FindLastChar('/', lastSlashIndex))
			{
				FString pureStoryMapName;

				for (int32 j = lastSlashIndex + 1; j < RMapFiles[i].Len() - 5; j++)
				{
					pureStoryMapName.AppendChar(RMapFiles[i][j]);
				}

				RMapFiles[i] = pureStoryMapName;
			}
		}

		return RMapFiles;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Capture the Flag Map Names", Keywords = "Get CTF Maps"), Category = "Game Data")
	static FORCEINLINE TArray<FString> GetCTFMapNames_p()
	{
		TArray<FString> CTFMapFiles;

		IFileManager::Get().FindFilesRecursive(CTFMapFiles, *FPaths::ProjectContentDir(), TEXT("CTF_*.umap"), true, false, false);

		for (int32 i = 0; i < CTFMapFiles.Num(); i++)
		{
			int32 lastSlashIndex = -1;
			if (CTFMapFiles[i].FindLastChar('/', lastSlashIndex))
			{
				FString pureStoryMapName;

				for (int32 j = lastSlashIndex + 1; j < CTFMapFiles[i].Len() - 5; j++)
				{
					pureStoryMapName.AppendChar(CTFMapFiles[i][j]);
				}

				CTFMapFiles[i] = pureStoryMapName;
			}
		}

		return CTFMapFiles;
	}
};
