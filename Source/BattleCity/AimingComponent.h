// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLECITY_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();
	virtual void AimAt(const FVector& AimLocation);
	virtual void SetTurret(UStaticMeshComponent* Component);

private:
	UStaticMeshComponent* Turret;
	
};
