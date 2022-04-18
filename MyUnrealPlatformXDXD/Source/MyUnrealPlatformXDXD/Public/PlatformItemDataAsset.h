// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlatformItemDataAsset.generated.h"

class UDataTable;

UCLASS()
class MYUNREALPLATFORMXDXD_API UPlatformItemDataAsset : public UDataAsset
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FName ItemName;
	UPROPERTY(EditAnywhere, Category = "Item Data")
	UDataTable* StatModifiers = nullptr;
};
