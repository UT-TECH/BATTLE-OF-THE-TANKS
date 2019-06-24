// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};



class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_OF_THE_TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties



	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);


	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = "Firing")
		void fire();

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;



private:
	UTankAimingComponent();

	void MoveBarrelToward(FVector AimDirection);


	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;


	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 12000;
	

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;


	UPROPERTY(EditAnywhere, Category = "Firing")
		float ReloadTimeInSeconds = 3;


	double LastFireTime = 0;

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool IsBarrelMoving();

	FVector AimDirection;
};
