// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
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
class PROJECTBRAWL_API ABrawlPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

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
		FText KillerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Status")
		FText KilledPlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Status")
		bool bIsPlayerActive = false;

	
};
