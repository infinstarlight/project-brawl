// Copyright (C) 2019 Gon�alo Marques - All Rights Reserved

#pragma once
#include "ReceiveInputType.generated.h"

UENUM(BlueprintType)
enum class EReceiveInputType : uint8
{
	None UMETA(DisplayName = "None"),
	Action UMETA(DisplayName = "Action"),
	Axis UMETA(DisplayName = "Axis")
};