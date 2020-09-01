// Copyright 2020 Property of Digiplay Gaming


#include "BrawlPlayerController.h"

ABrawlPlayerController::ABrawlPlayerController()
{
	TeamId = FGenericTeamId(10);
}

void ABrawlPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABrawlPlayerController, PlayerCurrentTeam);
	DOREPLIFETIME(ABrawlPlayerController, SenderNewMessage);
	//DOREPLIFETIME(ABrawlPlayerController, PlayerCurrentTeam);
}

FGenericTeamId ABrawlPlayerController::GetGenericTeamId() const
{
	return TeamId;
}