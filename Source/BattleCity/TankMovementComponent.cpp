// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankMovementComponent.h"
#include "TrackComponent.h"

void UTankMovementComponent::Initialise(UTrackComponent* Left, UTrackComponent* Right) {
	if (!ensure(Left && Right)) { return; }
	this->Left = Left;
	this->Right = Right;
}


void UTankMovementComponent::Move(float Throw) {
	if (!ensure(Left && Right)) { return; }

	Left->SetThrottle(Throw);
	Right->SetThrottle(Throw);
}

void UTankMovementComponent::Turn(float Throw) {
	if (!ensure(Left && Right)) { return; }

	Left->SetThrottle(Throw);
	Right->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {
	// Get forward direction and direction pawn is intent to move
	FVector Forward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector Intention = MoveVelocity.GetSafeNormal();

	// Move to asked direction
	float Throw = FVector::DotProduct(Forward, Intention);
	Move(Throw);

	// Rotate to asked direction
	float Rotate = FVector::CrossProduct(Forward, Intention).Z;
	Turn(Rotate);
}
