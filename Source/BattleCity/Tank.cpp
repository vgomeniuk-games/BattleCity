// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Tank.h"
#include "AimingComponent.h"
#include "TurretComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Init components
	AimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("AimingComponent"));
}

void ATank::AimAt(FVector AimLocation) {
	AimingComponent->AimAt(AimLocation, LaunchSpeed);
}

void ATank::Fire() {
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
}


void ATank::SetTurret(UTurretComponent* Turret) {
	AimingComponent->SetTurret(Turret);
}
