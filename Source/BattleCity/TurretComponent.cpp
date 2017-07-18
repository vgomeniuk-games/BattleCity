// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TurretComponent.h"


void UTurretComponent::Rotate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float Delta = RelativeSpeed * MaxRotationSpeed * GetWorld()->DeltaTimeSeconds;
	SetRelativeRotation(FRotator(0, RelativeRotation.Yaw + Delta, 0));
}

