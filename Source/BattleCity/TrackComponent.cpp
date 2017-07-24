// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TrackComponent.h"

UTrackComponent::UTrackComponent() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UTrackComponent::BeginPlay() {
	OnComponentHit.AddDynamic(this, &UTrackComponent::OnHit);
}

void UTrackComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) {
	Drive();
	ApplySidewaysCorrectionForce();
	CurrentThrottle = 0;  // Reset
}

void UTrackComponent::ApplySidewaysCorrectionForce() {
	float Slip = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	FVector Correction = -Slip / GetWorld()->GetDeltaSeconds() * GetRightVector();
	UStaticMeshComponent* Root = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	FVector CorrectionForce = (Root->GetMass() * Correction) / 2; // Correction Force per 1 of 2 Tracks
	Root->AddForce(CorrectionForce);
}

void UTrackComponent::SetThrottle(float Throttle) {
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UTrackComponent::Drive()
{
	FVector Force = GetForwardVector() * CurrentThrottle * TrackMax;
	FVector Location = GetSocketLocation(FName("ForceLocation"));
	UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	Root->AddForceAtLocation(Force, Location);
}
