#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformItem.generated.h"

class UPlatformItemDataAsset;

UCLASS()
class MYUNREALPLATFORMXDXD_API APlatformItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformItem();

	UPROPERTY(EditAnywhere, Category = "Item Data")
	UPlatformItemDataAsset* ItemData = nullptr;
};
