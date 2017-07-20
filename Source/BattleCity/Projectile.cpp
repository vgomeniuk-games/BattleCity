// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrMovComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	PrMovComponent->bAutoActivate = false;
}

void AProjectile::Launch(float Speed) {
	PrMovComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	PrMovComponent->Activate();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

