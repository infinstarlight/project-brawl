// Fill out your copyright notice in the Description page of Project Settings.


#include "BrawlAIController.h"

ABrawlAIController::ABrawlAIController()
{
	SetGenericTeamId(FGenericTeamId(5));
}

ETeamAttitude::Type ABrawlAIController::GetTeamAttitudeTowards(const AActor & Other) const
{
	if (const APawn* OtherPawn = Cast<APawn>(&Other)) {

		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			//Other controllers with an ID of 5 are Friendly
			FGenericTeamId OtherTeamID = TeamAgent->GetGenericTeamId();
			if (OtherTeamID == 5)
			{
				return ETeamAttitude::Friendly;
			}
			//Controllers with an ID of 10 are Hostile
			if (OtherTeamID == 10)
			{
				return ETeamAttitude::Hostile;
			}
		}
	}

	return ETeamAttitude::Neutral;
}
