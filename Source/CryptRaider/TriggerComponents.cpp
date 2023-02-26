// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponents.h"

void UTriggerComponents::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("Trigger componenets alive"));
}