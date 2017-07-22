// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshSocket.h"
#include "Projectile.h"
#include "AimingComponent.h"
#include "TurretComponent.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Init components
	AimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("AimingComponent"));
	MovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("MovementComponent"));
}

void ATank::AimAt(FVector AimLocation) {
	AimingComponent->AimAt(AimLocation, LaunchSpeed);
}

void ATank::Fire() {
	bool bIsReloading = (FPlatformTime::Seconds() - LastShootTime) <= ReloadTime;
	if ( !Muzzle || !Projectile || bIsReloading ) { return; }
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
