// Fill out your copyright notice in the Description page of Project Settings.


#include "BrawlLMPViewportClient.h"

bool UBrawlLMPViewportClient::InputKey(const FInputKeyEventArgs & EventArgs)
{

	// Map the gamepad to the next player index (so 1st controller is player index 1, etc.)
	if (EventArgs.IsGamepad())
	{
		return Super::InputKey(EventArgs.Viewport, EventArgs.ControllerId + 1, EventArgs.Key, EventArgs.Event, EventArgs.AmountDepressed, true);
	}
	else
	{
		return Super::InputKey(EventArgs);
	}
	//if (bGamepad)
	//{
	//	return Super::InputKey(myInputKeyEventArgs);
	//	
	//	//return Super::InputKey(Viewport, ControllerId + 1, Key, EventType, AmountDepressed, bGamepad);
	//}
	//else
	//{
	//	return Super::InputKey(Viewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);
	//}
}

bool UBrawlLMPViewportClient::InputAxis(FViewport* myViewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples, bool bGamepad)
{
	if (bGamepad)
	{
		// Map the gamepad to the next player index (so 1st controller is player index 1, etc.)
		return Super::InputAxis(myViewport, ControllerId + 1, Key, Delta, DeltaTime, NumSamples, bGamepad);
	}
	else
	{
		return Super::InputAxis(myViewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
	}
}
