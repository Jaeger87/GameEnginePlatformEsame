// Fill out your copyright notice in the Description page of Project Settings.


#include "CatStats.h"
#include "ReflectionUtilsFunctionLibrary.h"

// Sets default values for this component's properties
UCatStats::UCatStats()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCatStats::UpdateStat(const FString& StatName, float StatValue)
{
	// Example
	//		StatName:	"HP"
	//		InPath:		"This." + StatName

	FString Path = "This";
	Path += ".";
	Path += StatName;

	void* OutObject = nullptr;
	FProperty* StatProperty = UReflectionUtilsFunctionLibrary::RetrieveProperty(this, Path, OutObject);

	if (StatProperty != nullptr)
	{
		FFloatProperty* FloatProperty = CastField<FFloatProperty>(StatProperty);
		if (FloatProperty != nullptr)
		{
			float Value = FMath::Clamp(StatValue, 0.f, 1.f);
			FloatProperty->SetPropertyValue_InContainer(OutObject, Value);

			if (GEngine != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Stats updated"));
			}
		}
	}
}

