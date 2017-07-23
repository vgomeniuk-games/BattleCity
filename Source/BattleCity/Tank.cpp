// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshSocket.h"
#include "Projectile.h"
#include "AimingComponent.h"
#include "TurretComponent.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank() {
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::AimAt(FVector AimLocation) {
	if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAt(AimLocation, LaunchSpeed);
}

void ATank::Fire() {
	bool bIsReloading = (FPlatformTime::Seconds() - LastShootTime) <= ReloadTime;

	if ( !ensure(Muzzle && Projectile) || bIsReloading ) { return; }
	AProjectile* Prj = GetWorld()->SpawnActor<AProjectile>(
		Projectile,
		Muzzle->GetSocketLocation(FName("Projectile")),
		Muzzle->GetSocketRotation(FName("Projectile"))
	);
	Prj->Launch(LaunchSpeed);
	LastShootTime = FPlatformTime::Seconds();
}


void ATank::Initialise(UTurretComponent* Turret) {
	Muzzle = Turret;
}
