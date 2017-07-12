// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AimingComponent.h"
#include "Tank.generated.h"

UCLASS()
class BATTLECITY_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector AimLocation);
	
	UFUNCTION(BlueprintCallable, meta = (Category = "Setup"))
	void SetTurret(UStaticMeshComponent* Turret);

protected:
	UAimingComponent* AimingComponent = nullptr;
	
};
