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

protected:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	class UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UParticleSystemComponent* ImpactBlast = nullptr;

	class UProjectileMovementComponent* PrMovComponent{ nullptr };

};
