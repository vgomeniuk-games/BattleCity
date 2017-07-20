// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTurretComponent;

UCLASS()
class BATTLECITY_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector AimLocation);
	
	UFUNCTION(BlueprintCallable, meta = (Category = "Setup"))
	void SetTurret(UTurretComponent* Turret);

	UFUNCTION(BlueprintCallable, meta = (Category = "Gameplay Actions"))
	void Fire();

protected:
	class UAimingComponent* AimingComponent{ nullptr };
	UTurretComponent* Muzzle{ nullptr };

private:

	UPROPERTY(EditAnywhere, Category="Firing")
	float LaunchSpeed = 1000;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<class AProjectile> Projectile;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float ReloadTime = 3.0f;
	double LastShootTime = 0.0;
};
