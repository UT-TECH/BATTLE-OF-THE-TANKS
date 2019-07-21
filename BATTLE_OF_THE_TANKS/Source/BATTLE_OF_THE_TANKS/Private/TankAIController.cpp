// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "Classes/GameFramework/Controller.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; } 
		
	if (!PlayerTank)
	{
		return;
	}
		MoveToActor(PlayerTank, AcceptanceRadius);
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		
		AimingComponent->fire();		 // TODO limit firing rate

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)){return;}

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}


}

void ATankAIController::OnPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Received!"))
	
	if (!(GetPawn())) { return; }

	GetPawn()->DetachFromControllerPendingDestroy();

}


