// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Classes/Kismet/GameplayStatics.h"
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector Hitlocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileStartingPoint"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		Hitlocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelToward(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim Found"), Time);
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming At: %s"), *TankName, *AimDirection.ToString());

	}
	else
	{

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Nothing to Aim"), Time);

	}

	UE_LOG(LogTemp, Warning, TEXT("Firing at :	%f"), LaunchSpeed)
}

void UTankAimingComponent::MoveBarrelToward(FVector AimDirection)
{
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}