// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{


	LeftTrack->SetTrottle(-Throw);
	RightTrack->SetTrottle(-Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{



	LeftTrack->SetTrottle(-Throw);
	RightTrack->SetTrottle(Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{



	LeftTrack->SetTrottle(Throw);
	RightTrack->SetTrottle(-Throw);
}