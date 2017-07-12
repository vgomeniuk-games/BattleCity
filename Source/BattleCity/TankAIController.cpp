// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin play: %s"), *(GetControlledTank()->GetName()));
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	ATank* player = GetPlayerTank();
	if (!player) { return; }
	GetControlledTank()->AimAt(player->GetActorLocation());
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerTank == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possesing tank"));
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}
