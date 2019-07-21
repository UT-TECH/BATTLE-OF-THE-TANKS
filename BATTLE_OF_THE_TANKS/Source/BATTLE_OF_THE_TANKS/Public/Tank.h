// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);
UCLASS()
class BATTLE_OF_THE_TANKS_API ATank : public APawn
{
	GENERATED_BODY()
public:

	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	)override;

	UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealthPercent() const;

	FTankDelegate OnDeath;
private:
	ATank();

	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(EditAnywhere, Category = "Health")
	int32 CurrentHealth= StartingHealth;
};
