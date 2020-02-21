// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ProjectBrawlGameModeBase.h"

void AProjectBrawlGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	//Call base function
	Super::PostLogin(NewPlayer);

	//Add new player to list of alive players
	AlivePlayers.Add(Cast<ABrawlPlayerController>(NewPlayer));

}

void AProjectBrawlGameModeBase::PlayerDied(ABrawlCharacter* KilledPlayer, ABrawlCharacter* Killer)
{



}

void AProjectBrawlGameModeBase::WinnerFound(ABrawlPlayerState* Winner)
{
	if (ABrawlGameState* GS = GetGameState < ABrawlGameState>())
	{
		GS->Winner = Winner;
	}
}

void AProjectBrawlGameModeBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AProjectBrawlGameModeBase, CurrentGameType);
	DOREPLIFETIME(AProjectBrawlGameModeBase, TeamAScore);
	DOREPLIFETIME(AProjectBrawlGameModeBase, TeamBScore);
}
