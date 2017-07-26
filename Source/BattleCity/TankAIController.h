// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECITY_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void Tick(float DeltaTime) override;
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossesedDeath();
private:
	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	float AcceptanceRadius = 300.0f;  // TODO: Find sensible value

};
