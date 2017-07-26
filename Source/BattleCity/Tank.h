// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLECITY_API ATank : public APawn
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;
private:
	ATank();
	void BeginPlay();

public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTankDelegate OnDeath;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay", DisplayName = "Health")
	int32 MaxHealth = 100;
	int32 CurrentHealth;
};
