// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "BrawlGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWinnerFound);

/**
 * 
 */
UCLASS()
class PROJECTBRAWL_API ABrawlGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> & OutLifetimeProps) const override;

	//The winner of the match
	UPROPERTY(ReplicatedUsing = OnRep_Winner, Transient, BlueprintReadOnly, Category = "Game State")
	class ABrawlPlayerState* Winner = nullptr;

	//Called when a player wins the match
	UFUNCTION()
		void OnRep_Winner();

	//Called to update UI on Player win
	UPROPERTY(BlueprintAssignable, Category = "Game State")
		FWinnerFound OnWinnerFound;
	
};
