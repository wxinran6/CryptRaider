// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponents.h"

UTriggerComponents::UTriggerComponents()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Display, TEXT("Constructiong"));

	// ...
}

void UTriggerComponents::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("Trigger componenets alive"));
}

void UTriggerComponents::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// UE_LOG(LogTemp, Display, TEXT("Tick componenets alive"));

	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	// if (Actors.Num() > 0)
	// {
	// 	FString ActorName = Actors[0]->GetActorNameOrLabel();
	// 	UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
	// }

	int32 index = 0;
	while (index < Actors.Num())
	{
		FString ActorName = Actors[index]->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
		++index;
	}
}
