// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator MyRotation = GetComponentRotation();
	FString RotationString = MyRotation.ToCompactString();
	UE_LOG(LogTemp, Display, TEXT("Grabber Rotation: %s"), *RotationString);
	// ...

	float Time = GetWorld()->TimeSeconds;
	UE_LOG(LogTemp, Display, TEXT("Current Time Is: %f"), Time);
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	float damage = 5;
	float& damageRef = damage; 

	PrintDamage(damage);
	UE_LOG(LogTemp, Display, TEXT("Old Damage: %f"), damageRef);
}

void UGrabber::PrintDamage(float& Damage)
{
	Damage = 2;
	UE_LOG(LogTemp, Display, TEXT("Damage:%f"), Damage);
}
