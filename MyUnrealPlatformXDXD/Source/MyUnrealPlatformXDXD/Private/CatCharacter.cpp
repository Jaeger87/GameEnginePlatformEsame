// Fill out your copyright notice in the Description page of Project Settings.


#include "CatCharacter.h"

#include "CatStats.h"
#include "CatInventory.h"

#include "PlatformItem.h"


ACatCharacter::ACatCharacter()
{
	catStats = CreateDefaultSubobject<UCatStats>(TEXT("stats"));
	InventoryComponent = CreateDefaultSubobject<UCatInventory>(TEXT("Inventory"));
}

void ACatCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	if (OtherActor == nullptr)
	{
		return;
	}

	bool bIsAnItem = OtherActor->IsA<APlatformItem>();

	if (bIsAnItem)
	{
		APlatformItem* Item = Cast<APlatformItem>(OtherActor);
		InventoryComponent->AddItem(Item);

		Item->Destroy();
	}
	
}
