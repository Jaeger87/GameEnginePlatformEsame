// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CatStats.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYUNREALPLATFORMXDXD_API UCatStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCatStats();
	void UpdateStat(const FString& StatName, float StatValue);

	UFUNCTION(BlueprintCallable)
	float GetStat(const FName StatFName) const;
	
	UFUNCTION(BlueprintCallable)
	void ConsumeStat(const FName StatFName, float consumeValue);
	
protected:
	// Called when the game starts
	UPROPERTY(EditAnywhere, Category="Stats", meta = (ClampMin = "1.0", ClampMax = "5.0", UIMin = "0.0", UIMax = "1.0"))
	float Speed = 1.0f;
	UPROPERTY(VisibleAnywhere)
	float InvincibleSeconds = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Stats", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AirFriction = 0.5f;
		
};
