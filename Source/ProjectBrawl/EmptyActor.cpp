// Copyright 2020 Property of Digiplay Gaming


#include "EmptyActor.h"

// Sets default values
AEmptyActor::AEmptyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEmptyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEmptyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

