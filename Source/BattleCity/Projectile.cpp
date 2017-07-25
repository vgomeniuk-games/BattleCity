// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

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

	// Setup Force applied to hit objects 
	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("ExplosionForce"));
	ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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
	ExplosionForce->FireImpulse();

	// Reset root and destroy Static Mesh not prevent colliding with other objects
	SetRootComponent(ImpactBlast);
	Mesh->DestroyComponent();

	// Apply damage
	UGameplayStatics::ApplyRadialDamage(
		this,
		FMath::RandRange(MinDamage, MaxDamage),
		GetActorLocation(),
		ExplosionForce->Radius,
		UDamageType::StaticClass(),
		TArray<AActor*>()
	);
	
	// Set timer to remove actor
	FTimerHandle _;
	GetWorld()->GetTimerManager().SetTimer(_, this, &AProjectile::OnExpire, ExpireDelay);
}

void AProjectile::OnExpire() {
	Destroy();
}

void AProjectile::Launch(float Speed) {
	PrMovComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	PrMovComponent->Activate();
}
