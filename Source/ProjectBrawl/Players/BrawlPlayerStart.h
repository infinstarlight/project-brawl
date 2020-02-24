// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "ProjectBrawl/Players/BrawlPlayerController.h"
#include "BrawlPlayerStart.generated.h"

/**
 *
 */
UCLASS()
class PROJECTBRAWL_API ABrawlPlayerStart : public APlayerStart
{
	GENERATED_BODY()

public:

	//Is this an active spawn point?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		bool bIsActive = false;

	//What team does this spawn work for?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		TEnumAsByte<EPlayerTeam> SpawnPlayerTeam; 

	//Is this spawn point near the enemy team?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		bool bIsNearEnemy = false;

	//What is the state of this spawn point?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		int32 SpawnState;

};
