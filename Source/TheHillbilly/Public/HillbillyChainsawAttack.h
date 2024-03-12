#pragma once

#include "CoreMinimal.h"
#include "BaseChainsawAttack.h"
#include "StatProperty.h"
#include "HillbillyChainsawAttack.generated.h"

class ADBDPlayer;

UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class THEHILLBILLY_API UHillbillyChainsawAttack : public UBaseChainsawAttack
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	FStatProperty _initialChainsawTurnRate;

	UPROPERTY(EditDefaultsOnly)
	FStatProperty _chainsawTurnRate;

	UPROPERTY(EditDefaultsOnly)
	FStatProperty _turnRateAdjustmentTime;

	UPROPERTY(EditDefaultsOnly)
	FStatProperty _overheatMaxSpeedOverride;

	UPROPERTY(EditDefaultsOnly)
	FStatProperty _overheatMaxSpeedAdjustmentTime;

	UPROPERTY(EditDefaultsOnly)
	FStatProperty _attackZoneScaleFactor;

	UPROPERTY(EditDefaultsOnly)
	FStatProperty _obstructionZoneScaleFactor;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAttackFinished(ADBDPlayer* player);

public:
	UHillbillyChainsawAttack();
};

FORCEINLINE uint32 GetTypeHash(const UHillbillyChainsawAttack) { return 0; }
