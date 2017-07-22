// Viktor Gomeniuk : https://github.com/vgomeniuk

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TrackComponent.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup = (Custom))
class BATTLECITY_API UTrackComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly, meta = (Category="Setup", DisplayName="Max Movement Force (Newtons)"))
	float TrackMax = 40000000.0f;
};
