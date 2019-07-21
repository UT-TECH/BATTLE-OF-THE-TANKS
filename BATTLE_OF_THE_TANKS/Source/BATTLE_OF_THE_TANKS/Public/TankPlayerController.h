// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLE_OF_THE_TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	


private:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;


	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.355;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimComprRef);

	UFUNCTION()
		void OnPossedTankDeath();


};
