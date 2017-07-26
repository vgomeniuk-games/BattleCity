// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankAIController.h"
#include "AimingComponent.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	UAimingComponent* Component = GetPawn()->FindComponentByClass<UAimingComponent>();
	APawn* Enemy = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (ensure(Enemy && GetPawn() && Component)) {
		MoveToActor(Enemy, AcceptanceRadius);
		Component->AimAt(Enemy->GetActorLocation());

		if (Component->GetState() == EFiringState::Locked) {
			Component->Fire();
		}
	}
}

void ATankAIController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {
		ATank* Possessed = Cast<ATank>(InPawn);
		if (ensure(Possessed)) { 
			Possessed->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossesedDeath);
		}
	}
}

void ATankAIController::OnPossesedDeath() {
	if (GetPawn()) {
		GetPawn()->DetachFromControllerPendingDestroy();
	}
}
