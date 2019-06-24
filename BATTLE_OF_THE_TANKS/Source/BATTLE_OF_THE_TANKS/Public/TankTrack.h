// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_OF_THE_TANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	   UFUNCTION(BlueprintCallable, Category = "Input")
		void SetTrottle(float Throttle);
	
		UPROPERTY(EditDefaultsOnly)	
			float TrackMaxDrivingForce= 45000000;
private:
	UTankTrack();

	
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	void ApplySidewaysForce();

	float CurrentThrottle = 0;
};
