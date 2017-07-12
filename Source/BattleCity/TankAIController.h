// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECITY_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
		
};
