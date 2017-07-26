// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Tank.h"

// Sets default values
ATank::ATank() {
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay() {
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) {
	int32 Damage = FPlatformMath::RoundToInt(DamageAmount);
	Damage = FMath::Clamp<int32>(Damage, 0, CurrentHealth);
	CurrentHealth -= Damage;
	if (CurrentHealth <= 0) {
		OnDeath.Broadcast();
	}
	return Damage;
}

float ATank::GetHealthPercent() const {
	return static_cast<float>(CurrentHealth) / static_cast<float>(MaxHealth);
}
