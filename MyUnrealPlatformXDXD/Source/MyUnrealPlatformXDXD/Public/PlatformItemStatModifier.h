#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"

#include "PlatformItemStatModifier.generated.h"

USTRUCT(BlueprintType)
struct FPlatformItemStatModifier : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Item")
	FString StatName;
	UPROPERTY(EditAnywhere, Category = "Item")
	float Value = 0.f;
};