// Copyright 2020 Property of Digiplay Gaming


#include "BrawlLMSGameMode.h"

void ABrawlLMSGameMode::PlayerDied(class ABrawlCharacter * KilledPlayer, class ABrawlCharacter * Killer)
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

void ABrawlLMSGameMode::WinnerFound(class ABrawlPlayerState* Winner)
{
	Super::WinnerFound(Winner);
}

