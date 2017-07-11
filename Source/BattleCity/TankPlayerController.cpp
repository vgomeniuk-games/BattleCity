// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}



