// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Static Mesh to display
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("ProjectileMesh"));
	SetRootComponent(Mesh);
	Mesh->SetNotifyRigidBodyCollision(true);

	// Create Particle System to display
	Blast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Blast"));
	Blast->AttachTo(RootComponent);

	// Create Movement component
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

