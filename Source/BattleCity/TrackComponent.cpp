// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TrackComponent.h"


void UTrackComponent::SetThrottle(float Throttle) {
	FVector Force = GetForwardVector() * Throttle * TrackMax;
	FVector Location = GetSocketLocation(FName("ForceLocation"));
	UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	Root->AddForceAtLocation(Force, Location);
}
