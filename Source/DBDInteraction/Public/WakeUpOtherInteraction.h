#pragma once

#include "CoreMinimal.h"
#include "ChargeableInteractionDefinition.h"
#include "WakeUpOtherInteraction.generated.h"

class UCurveFloat;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UWakeUpOtherInteraction : public UChargeableInteractionDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* _wakeUpTimeCurve;

public:
	UWakeUpOtherInteraction();
};

FORCEINLINE uint32 GetTypeHash(const UWakeUpOtherInteraction) { return 0; }
