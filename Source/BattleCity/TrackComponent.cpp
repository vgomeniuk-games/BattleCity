// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TrackComponent.h"

UTrackComponent::UTrackComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UTrackComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Fix sideways slip
	float Slip = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	FVector Correction = -Slip / DeltaTime * GetRightVector();
	UStaticMeshComponent* Root = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	FVector CorrectionForce = (Root->GetMass() * Correction) / 2; // Correction Force per 1 of 2 Tracks
	Root->AddForce(CorrectionForce);
}

void UTrackComponent::SetThrottle(float Throttle) {
	FVector Force = GetForwardVector() * Throttle * TrackMax;
	FVector Location = GetSocketLocation(FName("ForceLocation"));
	UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	Root->AddForceAtLocation(Force, Location);
}
