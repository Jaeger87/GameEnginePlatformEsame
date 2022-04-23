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

		if (InActor != nullptr)
		{
			TArray<UActorComponent*> Components;
			InActor->GetComponents(Components); //Molto inefficente

			for (size_t ComponentIndex = 0; ComponentIndex < Components.Num(); ++ComponentIndex)
			{
				UActorComponent* Component = Components[ComponentIndex];
				if (ObjectString.Equals(Component->GetName(), ESearchCase::IgnoreCase))
				{
					TargetObj = Component;
					break;
				}
			}
		}
	}

	OutTarget = TargetObj;

	FProperty* OutProperty;

	if (ensureAlways(TargetObj))
	{
		UClass* TargetClass = TargetObj->GetClass();
		FName PropertyName = FName(*PropertyString);
		
		OutProperty = TargetClass->FindPropertyByName(PropertyName);
	}
	else
	{
		OutProperty = nullptr;
	}

	return OutProperty;
}

FProperty* UReflectionUtilsFunctionLibrary::RetrieveProperty(const UObject* InObject, const FName InPropertyFname)
{
	if (InObject == nullptr)
	{
		return nullptr;
	}

	const UClass* TargetClass = InObject->GetClass();
	FProperty* OutProperty;

	OutProperty = TargetClass->FindPropertyByName(InPropertyFname);
	
	return OutProperty;
	
}
