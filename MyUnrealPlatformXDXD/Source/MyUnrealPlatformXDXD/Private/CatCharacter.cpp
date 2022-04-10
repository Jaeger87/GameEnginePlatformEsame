// Fill out your copyright notice in the Description page of Project Settings.


#include "CatCharacter.h"

#include "CatStats.h"

ACatCharacter::ACatCharacter()
{
	catStats = CreateDefaultSubobject<UCatStats>(TEXT("stats"));
}
