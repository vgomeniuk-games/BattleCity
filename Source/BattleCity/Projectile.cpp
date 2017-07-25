// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"

// Sets default values
AProjectile::AProjectile() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Static Mesh to display
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("ProjectileMesh"));
	SetRootComponent(Mesh);
	Mesh->SetNotifyRigidBodyCollision(true);

	// Create Particle System to display on Launch
	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));
	LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// Create Particle System to display on colliding with other object
	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("ImpactBlast"));
	ImpactBlast->bAutoActivate = false;
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// Create Movement component
	PrMovComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	PrMovComponent->bAutoActivate = false;
}

void AProjectile::BeginPlay() {
	Super::BeginPlay();
	Mesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) {
	LaunchBlast->Deactivate();
	ImpactBlast->Activate();
}

void AProjectile::Launch(float Speed) {
	PrMovComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	PrMovComponent->Activate();
}
