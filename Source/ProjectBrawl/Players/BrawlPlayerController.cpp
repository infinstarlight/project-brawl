// Copyright 2020 Property of Digiplay Gaming


#include "BrawlPlayerController.h"

void ABrawlPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABrawlPlayerController, PlayerCurrentTeam);
	DOREPLIFETIME(ABrawlPlayerController, SenderNewMessage);
	//DOREPLIFETIME(ABrawlPlayerController, PlayerCurrentTeam);
}