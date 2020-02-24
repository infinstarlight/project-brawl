// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectBrawl/Players/BrawlCharacter.h"
#include "ProjectBrawl/Players/BrawlPlayerController.h"
#include "ProjectBrawl/Players/BrawlPlayerState.h"
#include "ProjectBrawl/Players/BrawlPlayerStart.h"
#include "ProjectBrawl/System/BrawlGameState.h"
#include "ProjectBrawlGameMode.generated.h"

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
class PROJECTBRAWL_API AProjectBrawlGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	//Used to populate array of active players
	virtual void PostLogin(APlayerController* NewPlayer) override;

	//Used to relay data to GameState
	virtual void PlayerDied(class ABrawlCharacter* KilledPlayer, class ABrawlCharacter* Killer);
	//Used to determine who won the game
	virtual void WinnerFound(class ABrawlPlayerState* Winner);

	////Used to spawn Player Character with desired class
	//UFUNCTION(Server, Reliable)
	//void Server_SpawnPlayer(class APlayerController* NewPC);


	//List of alive players, used for BR game mode, Transient means it is emptied at start
	UPROPERTY(Transient)
		TArray<class ABrawlPlayerController*> AlivePlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Status")
		TArray<class APlayerController*> CurrentPlayerControllers;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Team A")
		TArray<ABrawlPlayerStart*> PossibleSpawnsTeamA;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Team B")
		TArray<ABrawlPlayerStart*> PossibleSpawnsTeamB;

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

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
