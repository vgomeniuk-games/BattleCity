// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

UENUM()
enum class EFiringState: uint8 {
	Reload, Aiming, Locked
};

class UTurretComponent;
class UMuzzleComponent;

UCLASS( ClassGroup=(Action), meta=(BlueprintSpawnableComponent) )
class BATTLECITY_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTurretComponent* Turret, UMuzzleComponent* Muzzle);

	virtual void AimAt(const FVector& AimLocation);

	UFUNCTION(BlueprintCallable, meta = (Category = "Gameplay Actions"))
	void Fire();

protected:
	virtual void RotateTurret(FVector DesiredDirection);

private:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);
	bool IsAiming();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Firing State")
	EFiringState State = EFiringState::Reload;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 1000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<class AProjectile> Projectile;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTime = 3.0f;
	double LastShootTime = FPlatformTime::Seconds();

	UTurretComponent* Turret;
	UMuzzleComponent* Muzzle;
	FVector AimDirection;
};
