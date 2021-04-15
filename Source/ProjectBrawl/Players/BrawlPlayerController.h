// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "Net/UnrealNetwork.h"
#include "BrawlPlayerController.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EPlayerTeam : uint8
{
	None,
	AlphaTeam,
	BravoTeam
};
UCLASS()
class PROJECTBRAWL_API ABrawlPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:

	ABrawlPlayerController();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Player Team")
		TEnumAsByte<EPlayerTeam> PlayerCurrentTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Status")
		bool bIsPlayerReadyToSpawn = false;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, Category = "Communication")
		FText SenderNewMessage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Communication")
		FText MessageSender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Status")
		FText KillerName_CPP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Status")
		FText KilledPlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Status")
		bool bIsPlayerActive = false;

	// Implement The Generic Team Interface 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
	FGenericTeamId TeamId;

	FGenericTeamId GetGenericTeamId() const;

	
};
