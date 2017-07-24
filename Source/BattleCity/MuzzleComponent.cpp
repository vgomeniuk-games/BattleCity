// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "MuzzleComponent.h"

void UMuzzleComponent::Elevate(float Degree) {
	float NormalizedElevation = FMath::Clamp<float>(Degree, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(NormalizedElevation, 0, 0));
}
