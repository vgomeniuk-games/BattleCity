// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Init components
	AimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("AimingComponent"));
}

void ATank::AimAt(FVector AimLocation) {
	AimingComponent->AimAt(AimLocation);
}


void ATank::SetTurret(UStaticMeshComponent* Turret) {
	AimingComponent->SetTurret(Turret);
}
