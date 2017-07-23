// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "MuzzleComponent.h"

void UMuzzleComponent::Elevate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float Delta = RelativeSpeed * ElevationSpeed * GetWorld()->DeltaTimeSeconds;
	float Elevation = FMath::Clamp<float>(RelativeRotation.Pitch + Delta, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
