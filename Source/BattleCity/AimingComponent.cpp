// Viktor Gomeniuk : https://github.com/vgomeniuk
#include "AimingComponent.h"
#include "CoreMinimal.h"
#include "Engine.h"
#include "TurretComponent.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UAimingComponent::AimAt(const FVector& AimLocation, float LaunchSpeed) {
	if (Turret == nullptr) { return; }

	// Try to calculate Launch Velocity based on possible projectile trajectory
	FVector LaunchVelocity;
	FVector StartLocation = Turret->GetSocketLocation(FName("Projectile"));
	bool bSolutionFound = UGameplayStatics::SuggestProjectileVelocity(
		this, LaunchVelocity, StartLocation, AimLocation,
		LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace
	);

	// If succeed
	if (bSolutionFound) {
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		RotateTurret(AimDirection);
	};
	
}


void UAimingComponent::SetTurret(UTurretComponent* Component) {
	Turret = Component;
}


void UAimingComponent::RotateTurret(FVector DesiredDirection) {
	// Calculate rotation difference and rotate turret respectively
	FRotator Delta = DesiredDirection.Rotation() - Turret->GetForwardVector().Rotation();
	FMath::Abs(Delta.Yaw) > 180 ? Turret->Rotate(-Delta.Yaw) : Turret->Rotate(Delta.Yaw);
}
