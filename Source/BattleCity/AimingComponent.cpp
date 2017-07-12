// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "AimingComponent.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UAimingComponent::AimAt(const FVector& AimLocation) {
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s"), *(GetOwner()->GetName()), *AimLocation.ToString());
}


void UAimingComponent::SetTurret(UStaticMeshComponent* Component) {
	Turret = Component;
}
