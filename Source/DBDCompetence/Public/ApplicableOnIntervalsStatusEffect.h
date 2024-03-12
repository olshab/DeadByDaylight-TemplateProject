#pragma once

#include "CoreMinimal.h"
#include "StatusEffect.h"
#include "ApplicableOnIntervalsStatusEffect.generated.h"

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class UApplicableOnIntervalsStatusEffect : public UStatusEffect
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	bool _startAsApplicable;

	UPROPERTY(EditDefaultsOnly)
	float _intervalTime;

public:
	UApplicableOnIntervalsStatusEffect();
};

FORCEINLINE uint32 GetTypeHash(const UApplicableOnIntervalsStatusEffect) { return 0; }
