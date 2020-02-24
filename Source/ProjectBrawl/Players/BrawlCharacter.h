// Copyright 2020 Property of Digiplay Gaming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BrawlCharacter.generated.h"

UCLASS()
class PROJECTBRAWL_API ABrawlCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABrawlCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
