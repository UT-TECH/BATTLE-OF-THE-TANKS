// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		GetControlledTank()->AimAT(GetPlayerTank()->GetActorLocation());
	}

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	if (!ControlledTank && !PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI_Controller IS NOT POSSESSING A TANK!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI_Controller IS POSSESSING:  %s and Found Player Tank: %s"), (*(ControlledTank->GetName())), (*(PlayerTank->GetName())));
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn){return nullptr;}

	return Cast<ATank>(PlayerPawn);

}
