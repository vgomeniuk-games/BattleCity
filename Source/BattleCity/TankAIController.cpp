// Viktor Gomeniuk : https://github.com/vgomeniuk

#include "TankAIController.h"
#include "AimingComponent.h"


void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	UAimingComponent* Component = GetPawn()->FindComponentByClass<UAimingComponent>();
	APawn* Enemy = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (ensure(Enemy && GetPawn() && Component)) {
		MoveToActor(Enemy, AcceptanceRadius);
		Component->AimAt(Enemy->GetActorLocation());
		Component->Fire();
	}
}
