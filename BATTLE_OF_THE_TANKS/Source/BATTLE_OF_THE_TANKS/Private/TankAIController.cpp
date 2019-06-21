// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; } 
		
		MoveToActor(PlayerTank, AcceptanceRadius);
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		AimingComponent->fire(); // TODO limit firing rate

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}


