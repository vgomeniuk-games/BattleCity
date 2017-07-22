// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankMovementComponent.h"
#include "TrackComponent.h"

void UTankMovementComponent::Initialise(UTrackComponent* Left, UTrackComponent* Right) {
	if (Left) { this->Left = Left; }
	if (Right) { this->Right = Right; }
}


void UTankMovementComponent::Move(float Throttle) {
	UE_LOG(LogTemp, Warning, TEXT("UTankMovementComponent::MoveForward: %f"), Throttle);
}


