#pragma once

#include "CoreMinimal.h"
#include "DBDTunableRowHandle.h"
#include "Spring2024StatusEffect.h"
#include "Spring2024SurvivorStatusEffect.generated.h"

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class USpring2024SurvivorStatusEffect : public USpring2024StatusEffect
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	FDBDTunableRowHandle _injuredVoiceLevelModifier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	FDBDTunableRowHandle _bloodDecalDurationModifier;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _crouchedInjuredVoiceLevelModifier;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _crouchedBloodDecalDurationModifier;

protected:
	UFUNCTION(BlueprintPure)
	FDBDTunableRowHandle GetInjuredVoiceLevelModifier();

	UFUNCTION(BlueprintPure)
	FDBDTunableRowHandle GetBloodDecalDurationModifier();

public:
	USpring2024SurvivorStatusEffect();
};

FORCEINLINE uint32 GetTypeHash(const USpring2024SurvivorStatusEffect) { return 0; }
