// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "ProjectBrawl/System/GameModes/ProjectBrawlGameMode.h"
#include "ProjectBrawlLMSGameMode.generated.h"

/**
 *
 */
UCLASS()
class PROJECTBRAWL_API AProjectBrawlLMSGameMode : public AProjectBrawlGameMode
{
	GENERATED_BODY()

	virtual void PlayerDied(class ABrawlCharacter* KilledPlayer, class ABrawlCharacter* Killer) override;

	virtual void WinnerFound(ABrawlPlayerState* Winner) override;

};
