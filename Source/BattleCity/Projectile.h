// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLECITY_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	AProjectile();
	void Launch(float Spped);
private:
	void BeginPlay();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	void OnExpire();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ExpireDelay = 5.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinDamage = 5.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDamage = 20.0f;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	class UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	class URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	class UProjectileMovementComponent* PrMovComponent = nullptr;

};
