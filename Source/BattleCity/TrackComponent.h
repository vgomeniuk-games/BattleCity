// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TrackComponent.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup = (TankMesh))
class BATTLECITY_API UTrackComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

private:
	UTrackComponent();
	void BeginPlay() override;

	void Drive();
	void ApplySidewaysCorrectionForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

protected:
	UPROPERTY(EditDefaultsOnly, meta = (Category = "Setup", DisplayName = "Max Movement Force (Newtons)"))
	float TrackMax = 20000000.0f;
	
private:
	float CurrentThrottle = 0;
};
