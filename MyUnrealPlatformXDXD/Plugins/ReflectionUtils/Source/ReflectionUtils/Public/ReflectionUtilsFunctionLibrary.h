// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReflectionUtilsFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class REFLECTIONUTILS_API UReflectionUtilsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:

	/*
	*  Examples:	This.CharacterStats.HP (InObject: AArenaCharacter)
	*				This.CharacterStats.MP (InObject: AArenaCharacter)
	*				
	*				This.CharacterMovement.Speed (InObject: AArenaCharacter)
	* 
	*				This.HP (InObject: UArenaCharacterStats)
	*/
	static FProperty* RetrieveProperty(UObject* InObject, const FString& InPath, void*& OutTarget);
};
