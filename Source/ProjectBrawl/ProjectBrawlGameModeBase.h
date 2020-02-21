// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Characters/BrawlPlayerController.h"
#include "Characters/BrawlPlayerState.h"
#include "Characters/BrawlCharacter.h"
#include "System/BrawlGameState.h"
#include "ProjectBrawlGameModeBase.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGameType : uint8
{
	None,
	Menus,
	Lobby,
	Deathmatch,
	TeamDeathmatch,
	CTF,
	Rush,
	LMS,
	Conquest

};
UCLASS()
class PROJECTBRAWL_API AProjectBrawlGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	//Used to populate array of active players
	virtual void PostLogin(APlayerController* NewPlayer) override;

	//Used to relay data to GameState
	virtual void PlayerDied(class ABrawlCharacter* KilledPlayer, class ABrawlCharacter* Killer);
	//Used to determine who won the game
	virtual void WinnerFound(class ABrawlPlayerState* Winner);

	//List of alive players, used for BR game mode, Transient means it is emptied at start
	UPROPERTY(Transient)
		TArray<class ABrawlPlayerController*> AlivePlayers;

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Rules")
		bool bEnableFriendlyFire = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Rules")
		bool bEnableBots = false;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Game Type")
		TEnumAsByte<EGameType> CurrentGameType;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Game Score")
		int32 TeamAScore = 0;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Game Score")
		int32 TeamBScore = 0;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> & OutLifetimeProps) const override;
	
};
