// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "Tank.h"

// Sets default values
ATank::ATank() {
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) {
	int32 Damage = FPlatformMath::RoundToInt(DamageAmount);
	Damage = FMath::Clamp<int32>(Damage, 0, CurrentHealth);
	CurrentHealth -= Damage;
	if (CurrentHealth <= 0) {
		// TODO: Die
	}
	UE_LOG(LogTemp, Warning, TEXT("Health left: %i"), CurrentHealth);
	return Damage;
}
