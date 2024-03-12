#pragma once

#include "CoreMinimal.h"
#include "BloodZoneBaseInteraction.h"
#include "BloodZoneDeactivationInteraction.generated.h"

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UBloodZoneDeactivationInteraction : public UBloodZoneBaseInteraction
{
	GENERATED_BODY()

public:
	UBloodZoneDeactivationInteraction();
};

FORCEINLINE uint32 GetTypeHash(const UBloodZoneDeactivationInteraction) { return 0; }
