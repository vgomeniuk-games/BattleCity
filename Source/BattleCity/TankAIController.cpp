// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin play: %s"), *(GetControlledTank()->GetName()));
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
