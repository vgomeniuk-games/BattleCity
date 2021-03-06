// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

UCLASS()
class BATTLECITY_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, meta = (Category = "Setup"))
	void OnAimingComponentFound(class UAimingComponent* Component);

protected:
	void AimTowardsCrosshair();
	bool TraceHitLocation(FVector& HitLocation) const;
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossesedDeath();

private:
	UPROPERTY(EditDefaultsOnly, Category = "CrosshairPosition", DisplayName = "X")
	float CrosshairPositionX = 0.5f;

	UPROPERTY(EditDefaultsOnly, meta=(Category = "CrosshairPosition", DisplayName="Y"))
	float CrosshairPositionY = 0.3333f;

	UPROPERTY(EditDefaultsOnly, meta = (Category = "Firing", DisplayName = "Fire Distance (m)"))
	float TraceRange = 25.0f;

};
