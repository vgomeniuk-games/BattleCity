// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

class UTurretComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLECITY_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAimingComponent();
	virtual void AimAt(const FVector& AimLocation, float LaunchSpeed);
	virtual void SetTurret(UTurretComponent* Component);

protected:
	virtual void RotateTurret(FVector DesiredDirection);

private:
	UTurretComponent* Turret;
	
};
