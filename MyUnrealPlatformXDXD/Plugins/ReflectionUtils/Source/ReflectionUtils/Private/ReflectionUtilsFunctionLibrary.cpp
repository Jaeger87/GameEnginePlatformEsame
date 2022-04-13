// Fill out your copyright notice in the Description page of Project Settings.


#include "ReflectionUtilsFunctionLibrary.h"

FProperty* UReflectionUtilsFunctionLibrary::RetrieveProperty(UObject* InObject, const FString& InPath, void*& OutTarget)
{

	// Example:

	//		This.HP

	//		CharacterStats.HP
	
	//ensureAlways(InObject);

	if (InObject == nullptr)
	{
		return nullptr;
	}

	FString ObjectString;
	FString PropertyString;
	bool bSucceded = InPath.Split(".", &ObjectString, &PropertyString);

	UObject* TargetObj = nullptr;
	if (ObjectString.Equals("This", ESearchCase::IgnoreCase))
	{
		TargetObj = InObject;
	}
	else
	{
		AActor* InActor = Cast<AActor>(InObject);
	}
}
