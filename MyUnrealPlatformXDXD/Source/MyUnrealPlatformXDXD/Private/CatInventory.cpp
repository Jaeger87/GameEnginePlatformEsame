// Fill out your copyright notice in the Description page of Project Settings.


#include "CatInventory.h"
#include "CatStats.h"

#include "PlatformLogContext.h"
#include "PlatformItemDataAsset.h"
#include "PlatformItem.h"

// Sets default values for this component's properties
UCatInventory::UCatInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCatInventory::InitializeComponent()
{
	Super::InitializeComponent();

	AActor* Owner = GetOwner();
	if (Owner != nullptr)
	{
		CharacterStats = Owner->FindComponentByClass<UCatStats>();
	}
}

void UCatInventory::UninitializeComponent()
{
	Super::UninitializeComponent();

	CharacterStats = nullptr;
}

void UCatInventory::AddItem(APlatformItem* i_Item)
{
	if (CharacterStats == nullptr)
	{
		UE_LOG(LogPlatform, Warning, TEXT("Missing Character Stats"));
		return;
	}

	if (i_Item == nullptr)
	{
		UE_LOG(LogPlatform, Warning, TEXT("Invalid Item"));
		return;
	}

	UPlatformItemDataAsset* DataAsset = i_Item->ItemData;

	if (DataAsset == nullptr)
	{
		UE_LOG(LogPlatform, Warning, TEXT("Invalid Itam DataAsset"));
		return;
	}
}

