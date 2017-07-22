// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankMovementComponent.h"
#include "TrackComponent.h"

void UTankMovementComponent::Initialise(UTrackComponent* Left, UTrackComponent* Right) {
	if (Left) { this->Left = Left; }
	if (Right) { this->Right = Right; }
}


void UTankMovementComponent::Move(float Throw) {
	Left->SetThrottle(Throw);
	Right->SetThrottle(Throw);
}

void UTankMovementComponent::Turn(float Throw) {
	Left->SetThrottle(Throw);
	Right->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {
	FVector Forward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector Intention = MoveVelocity.GetSafeNormal();
	float Throw = FVector::DotProduct(Forward, Intention);
	Move(Throw);
}
