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
			FloatProperty->SetPropertyValue_InContainer(OutObject, StatValue);

			if (GEngine != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Stats updated"));
			}
		}
	}
}

float UCatStats::GetStat(const FName StatFName) const
{
	FProperty* StatProperty = UReflectionUtilsFunctionLibrary::RetrieveProperty(this, StatFName);
	if (StatProperty != nullptr)
	{
		FFloatProperty* FloatProperty = CastField<FFloatProperty>(StatProperty);
		if (FloatProperty != nullptr)
		{
			return FloatProperty->GetPropertyValue_InContainer(this);
		}
	}
	return FLT_MIN;
}

