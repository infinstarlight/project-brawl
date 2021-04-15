// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Engine/GameViewportClient.h"
#include "UnrealClient.h"
#include "BrawlLMPViewportClient.generated.h"

/**
 *
 */
UCLASS()
class PROJECTBRAWL_API UBrawlLMPViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
		virtual bool InputKey(const FInputKeyEventArgs& EventArgs) override;
	virtual bool InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples, bool bGamepad) override;
};
