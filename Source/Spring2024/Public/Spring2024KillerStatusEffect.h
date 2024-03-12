#pragma once

#include "CoreMinimal.h"
#include "DBDTunableRowHandle.h"
#include "Spring2024StatusEffect.h"
#include "Spring2024KillerStatusEffect.generated.h"

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class USpring2024KillerStatusEffect : public USpring2024StatusEffect
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _lungeAttackCooldownModifier;

	UPROPERTY(EditDefaultsOnly)
	float _activationTimerDuration;

public:
	USpring2024KillerStatusEffect();
};

FORCEINLINE uint32 GetTypeHash(const USpring2024KillerStatusEffect) { return 0; }
