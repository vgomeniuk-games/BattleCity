// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	// Trace to world position
	FVector HitLocation;
	if (TraceHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::TraceHitLocation(FVector& HitLocation) const {
	// Get crosshair's posiotion
	struct { int32 x; int32 y; } Viewport;
	GetViewportSize(Viewport.x, Viewport.y);
	FVector2D ScreenPosition = FVector2D(Viewport.x * CrosshairPositionX, Viewport.y * CrosshairPositionY);

	// Transform 2d crosshair position on screen to actual look direction
	FVector LookDirection;
	{
		FVector _;  // Unused/ Will be removed once goes out of block's scope
		if (!DeprojectScreenPositionToWorld(ScreenPosition.X, ScreenPosition.Y, _, LookDirection)) {
			return false;
		}
	}

	// Trace along found direction
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + LookDirection * TraceRange * 100;  // Measurement: cm => m
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}