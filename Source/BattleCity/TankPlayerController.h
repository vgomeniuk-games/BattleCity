// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "Tank.h"
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
	virtual ATank* GetControlledTank() const;

private:
	void AimTowardsCrosshair();
	bool TraceHitLocation(FVector& HitLocation) const;

private:
	UPROPERTY(EditAnywhere, Category = "CrosshairPosition", DisplayName = "X")
	float CrosshairPositionX = 0.5f;

	UPROPERTY(EditAnywhere, meta=(Category = "CrosshairPosition", DisplayName="Y"))
	float CrosshairPositionY = 0.3333f;

	UPROPERTY(EditAnywhere, meta = (Category = "Firing", DisplayName = "Fire Distance (m)"))
	float TraceRange = 500.0f;

};
