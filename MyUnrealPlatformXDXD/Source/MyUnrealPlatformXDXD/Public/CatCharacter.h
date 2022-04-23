// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "CatCharacter.generated.h"

class UCatStats;
class UCatInventory;

/**
 * 
 */
UCLASS()
class MYUNREALPLATFORMXDXD_API ACatCharacter : public APaperCharacter
{
	GENERATED_BODY()


	public:
		ACatCharacter();

		virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	protected:
		UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
		UCatStats* catStats;
		UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UCatInventory* InventoryComponent;
};
