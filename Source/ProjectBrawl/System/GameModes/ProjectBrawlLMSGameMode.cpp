// Copyright 2020 Property of Digiplay Gaming


#include "ProjectBrawlLMSGameMode.h"

void AProjectBrawlLMSGameMode::PlayerDied(ABrawlCharacter * KilledPlayer, ABrawlCharacter * Killer)
{
	Super::PlayerDied(KilledPlayer, Killer);
	if (KilledPlayer)
	{
		if (ABrawlPlayerController* PC = Cast<ABrawlPlayerController>(KilledPlayer->GetController()))
		{
			AlivePlayers.RemoveSingle(PC);
		}

		if (AlivePlayers.Num() == 1 && AlivePlayers.IsValidIndex(0))
		{
			WinnerFound(Cast<ABrawlPlayerState>(AlivePlayers[0]->PlayerState));
		}
	}
}

void AProjectBrawlLMSGameMode::WinnerFound(ABrawlPlayerState * Winner)
{
	Super::WinnerFound(Winner);
}
