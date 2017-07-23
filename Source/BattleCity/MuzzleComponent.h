// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "MuzzleComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup = (TankMesh))
class BATTLECITY_API UMuzzleComponent : public UArrowComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup", DisplayName="Elevation Speed (degree-per-second)")
	float ElevationSpeed = 25;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevation = 50;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevation = -15;

};
