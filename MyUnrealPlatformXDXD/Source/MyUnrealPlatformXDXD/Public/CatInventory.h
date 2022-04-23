// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CatInventory.generated.h"

class APlatformItem;
class UCatStats;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYUNREALPLATFORMXDXD_API UCatInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCatInventory();


	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;
	void AddItem(APlatformItem* i_Item);
	
	UPROPERTY(Transient)
	UCatStats* CharacterStats = nullptr;
		
};
