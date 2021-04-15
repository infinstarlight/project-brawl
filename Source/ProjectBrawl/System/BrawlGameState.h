// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "BrawlGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWinnerFound);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameEnded);

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Players")
		TArray<APlayerController*> PlayersReadyToStart; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Bots")
		TArray<AController*> BotControllers_TeamA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Bots")
		TArray<AController*> BotControllers_TeamB;

	//Called when a player wins the match
	UFUNCTION()
		void OnRep_Winner();

	//Called to update UI on Player win
	UPROPERTY(BlueprintAssignable, Category = "Game State")
		FWinnerFound OnWinnerFound;

	//Called to update UI on Generic Match End
	UPROPERTY(BlueprintAssignable, Category = "Game State")
		FGameEnded OnGameEnded;

	//Time remaining in match
	UPROPERTY(Replicated, EditDefaultsOnly, BlueprintReadWrite, Category = "Game State")
		float MatchTimeRemaining = 0.0f;

	//Time at the start of the match
	UPROPERTY(Replicated, EditDefaultsOnly, BlueprintReadWrite, Category = "Game State")
		float StartingMatchTime = 0.0f;
	
};
