// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"







void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI_Controller IS NOT POSSESSING A TANK!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI_Controller IS POSSESSING A TANK! : %s"), *(ControlledTank->GetName()));
	}
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI_Controller CAN'T FIND PLAYER TANK !"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI_Controller FOUND PLAYER TANK ! : %s"), *(PlayerTank->GetName()));
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