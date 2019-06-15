// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent),hidecategories = ("Collision"))
class BATTLE_OF_THE_TANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreePerSecond = 10;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegree = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegree = 0;
	
};
