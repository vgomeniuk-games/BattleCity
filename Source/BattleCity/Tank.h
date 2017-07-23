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
	void Initialise(UTurretComponent* Turret);

	UFUNCTION(BlueprintCallable, meta = (Category = "Gameplay Actions"))
	void Fire();

protected:
	UTurretComponent* Muzzle = nullptr;  // TODO: Remove

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<class AProjectile> Projectile;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 1000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTime = 3.0f;
	double LastShootTime = 0.0;
};
