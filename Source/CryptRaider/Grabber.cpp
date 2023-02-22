// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

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
	UPhysicsHandleComponent* PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("Physics handle is %s"),*PhysicsHandle->GetName()); 
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("no physics handler found!"));
	}
	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void UGrabber::PrintDamage(float& Damage)
{
	Damage = 2;
	UE_LOG(LogTemp, Display, TEXT("Damage:%f"), Damage);
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Display, TEXT("Released grabber"));
}

void UGrabber::Grab()
{
	FRotator MyRotation = GetComponentRotation();
	FString RotationString = MyRotation.ToCompactString();
	UE_LOG(LogTemp, Display, TEXT("Grabber Rotation: %s"), *RotationString);
	// ...

	float Time = GetWorld()->TimeSeconds;
	UE_LOG(LogTemp, Display, TEXT("Current Time Is: %f"), Time);
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);
	DrawDebugSphere(GetWorld(), End, 10, 10, FColor::Blue, false, 5);

	float damage = 5;
	float& damageRef = damage; 

	// PrintDamage(damage);
	// UE_LOG(LogTemp, Display, TEXT("Old Damage: %f"), damageRef);
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, Sphere);
		
	if(HasHit)
	{
		DrawDebugSphere(GetWorld(), HitResult.Location, 10, 10, FColor::Green, false, 5);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10, 10, FColor::Red, false, 5);
		AActor* HitActor = HitResult.GetActor();

		UE_LOG(LogTemp, Display, TEXT("Hit actor: %s"), *HitActor->GetActorNameOrLabel());
		

	}
	else{
		UE_LOG(LogTemp, Display, TEXT("No actor hit"));
	}
}