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
	// Sets default values for this actor's properties
	AProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Launch(float Spped);
protected:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	class UParticleSystemComponent* Blast = nullptr;

	class UProjectileMovementComponent* PrMovComponent{ nullptr };
	
};
