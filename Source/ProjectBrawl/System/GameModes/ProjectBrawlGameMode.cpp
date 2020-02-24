// Copyright 2020 Property of Digiplay Gaming


#include "ProjectBrawlGameMode.h"


void AProjectBrawlGameMode::PostLogin(APlayerController* NewPlayer)
{
	//Call base function
	Super::PostLogin(NewPlayer);

	//Add new player to list of alive players
	AlivePlayers.Add(Cast<ABrawlPlayerController>(NewPlayer));

}

void AProjectBrawlGameMode::PlayerDied(ABrawlCharacter* KilledPlayer, ABrawlCharacter* Killer)
{
}

void AProjectBrawlGameMode::WinnerFound(ABrawlPlayerState* Winner)
{
	if (ABrawlGameState* GS = GetGameState < ABrawlGameState>())
	{
		GS->Winner = Winner;
	}
}



//void AProjectBrawlGameMode::Server_SpawnPlayer(APlayerController * NewPC)
//{
//
//}
//
//void AProjectBrawlGameMode::Server_SpawnPlayer_Implementation(APlayerController* NewPC)
//{
//
//}

//bool AProjectBrawlGameMode::Server_SpawnPlayer_Validate(APlayerController* NewPC)
//{
//	return true;
//}

void AProjectBrawlGameMode::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AProjectBrawlGameMode, CurrentGameType);
	DOREPLIFETIME(AProjectBrawlGameMode, TeamAScore);
	DOREPLIFETIME(AProjectBrawlGameMode, TeamBScore);
}
