// Viktor Gomeniuk : https://github.com/vgomeniuk
#include "AimingComponent.h"
#include "CoreMinimal.h"
#include "Engine.h"
#include "TurretComponent.h"
#include "Projectile.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent() {
	PrimaryComponentTick.bCanEverTick = true;;
}

void UAimingComponent::AimAt(const FVector& AimLocation) {
	if (!ensure(Turret)) { return; }

	// Try to calculate Launch Velocity based on possible projectile trajectory
	FVector LaunchVelocity;
	FVector StartLocation = Turret->GetSocketLocation(FName("Projectile"));
	bool bSolutionFound = UGameplayStatics::SuggestProjectileVelocity(
		this, LaunchVelocity, StartLocation, AimLocation,
		LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace
	);

	// If succeed
	if (bSolutionFound) {
		AimDirection = LaunchVelocity.GetSafeNormal();
		RotateTurret(AimDirection);
	};
	
}

void UAimingComponent::Fire() {
	if (!ensure(Turret && Projectile)) { return; }
	if (State != EFiringState::Reload) {
		AProjectile* Prj = GetWorld()->SpawnActor<AProjectile>(
			Projectile,
			Turret->GetSocketLocation(FName("Projectile")),
			Turret->GetSocketRotation(FName("Projectile")));
		Prj->Launch(LaunchSpeed);
		LastShootTime = FPlatformTime::Seconds();
	}
}

void UAimingComponent::Initialise(UTurretComponent* Component) {
	Turret = Component;
}

void UAimingComponent::RotateTurret(FVector DesiredDirection) {
	// Calculate rotation difference and rotate turret respectively
	FRotator Delta = DesiredDirection.Rotation() - Turret->GetForwardVector().Rotation();
	FMath::Abs(Delta.Yaw) > 180 ? Turret->Rotate(-Delta.Yaw) : Turret->Rotate(Delta.Yaw);
}

void UAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
	if ((FPlatformTime::Seconds() - LastShootTime) <= ReloadTime) {
		State = EFiringState::Reload;
		return;
	}
	IsAiming() ? State = EFiringState::Aiming : State = EFiringState::Locked;
}

bool UAimingComponent::IsAiming() {
	if (!ensure(Turret)) { return false; }
	FVector Forward = Turret->GetForwardVector();
	return !Forward.Equals(AimDirection, 0.01);
}

