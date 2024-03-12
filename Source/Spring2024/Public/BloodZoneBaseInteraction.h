#pragma once

#include "CoreMinimal.h"
#include "BasicChargeableInteraction.h"
#include "BloodZoneBaseInteraction.generated.h"

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UBloodZoneBaseInteraction : public UBasicChargeableInteraction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	float _killerFacingTolerance;

public:
	UBloodZoneBaseInteraction();
};

FORCEINLINE uint32 GetTypeHash(const UBloodZoneBaseInteraction) { return 0; }
