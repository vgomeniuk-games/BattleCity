// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

UENUM()
enum class EFiringState: uint8 {
	Reload, Aiming, Locked
};

class UTurretComponent;

UCLASS( ClassGroup=(Action), meta=(BlueprintSpawnableComponent) )
class BATTLECITY_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTurretComponent* Component);

	virtual void AimAt(const FVector& AimLocation);

protected:
	virtual void RotateTurret(FVector DesiredDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Firing State")
	EFiringState State = EFiringState::Reload;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 1000;

	UTurretComponent* Turret;
	
};
