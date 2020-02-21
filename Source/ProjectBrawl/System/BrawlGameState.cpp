// Copyright 2020 Property of Digiplay Gaming


#include "BrawlGameState.h"

void ABrawlGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABrawlGameState, Winner);
}

void ABrawlGameState::OnRep_Winner()
{
	//Call UI function on all players
	OnWinnerFound.Broadcast();
}
