// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankPlayerController.h"
#include "AimingComponent.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	// Generate event to pass Component reference
	UAimingComponent* Component = GetPawn()->FindComponentByClass<UAimingComponent>();
	if (ensure(Component)) {
		OnAimingComponentFound(Component);
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetPawn()) { return; }

	UAimingComponent* Component = GetPawn()->FindComponentByClass<UAimingComponent>();
	if (!ensure(Component)) { return; }

	// Trace to world position
	FVector HitLocation;
	if (TraceHitLocation(HitLocation)) {
		Component->AimAt(HitLocation);
	}
}

void ATankPlayerController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {
		ATank* Possessed = Cast<ATank>(InPawn);
		if (ensure(Possessed)) {
			Possessed->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossesedDeath);
		}
	}
}

void ATankPlayerController::OnPossesedDeath() {
	StartSpectatingOnly();
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
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Camera)) {
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}