// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

UENUM()
enum class EFiringState: uint8 {
	Reload, Aiming, Locked, OutOfAmmo
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

	UFUNCTION(BlueprintCallable, Category = "Gameplay Actions")
	void Fire();

	EFiringState GetState() const;

	UFUNCTION(BlueprintCallable, Category="Firing")
	int32 GetAmmo() const;

protected:
	virtual void RotateTowards(FVector DesiredDirection);
	bool IsAiming();

private:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Firing")
	EFiringState State = EFiringState::Reload;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 1000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<class AProjectile> Projectile;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTime = 3.0f;
	double LastShootTime = FPlatformTime::Seconds();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 AmmoAmount = 3;

	UTurretComponent* Turret;
	UMuzzleComponent* Muzzle;
	FVector AimDirection;
};
