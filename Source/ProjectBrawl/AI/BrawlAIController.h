// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GenericTeamAgentInterface.h"
#include "BrawlAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBRAWL_API ABrawlAIController : public AAIController
{
	GENERATED_BODY()

	ABrawlAIController();

public:
	//Overriding this function
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
		FGenericTeamId TeamId;

	
};
