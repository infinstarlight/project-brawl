// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "ProjectBrawlGameModeBase.h"
#include "BrawlLMSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBRAWL_API ABrawlLMSGameMode : public AProjectBrawlGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PlayerDied(class ABrawlCharacter* KilledPlayer, class ABrawlCharacter* Killer) override;
	
	virtual void WinnerFound(ABrawlPlayerState* Winner) override;

};
