// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController IS NOT POSSESSING A TANK!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController IS POSSESSING A TANK! : %s"), *(ControlledTank->GetName()));
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
