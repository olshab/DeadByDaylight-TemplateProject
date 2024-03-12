#pragma once

#include "CoreMinimal.h"
#include "ChargeableInteractionDefinition.h"
#include "GameplayTagContainer.h"
#include "TunableStat.h"
#include "DBDTunableRowHandle.h"
#include "GameEventData.h"
#include "K35KillerShootAreaBlastTravelProjectileChargeableInteractionDefinition.generated.h"

class UCurveFloat;
class ASlasherPlayer;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UK35KillerShootAreaBlastTravelProjectileChargeableInteractionDefinition : public UChargeableInteractionDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _secondsToCharge;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _secondsCooldown;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _gracePeriodPercentage;

	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* _improvedNavigationSpeedCurve;

private:
	UFUNCTION()
	void OnKillerSet(ASlasherPlayer* killer);

	UFUNCTION()
	void OnIntroCompleted();

	UFUNCTION()
	void OnChargeComplete();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_UpdateLastTimeLaunched();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_CompleteCooldown();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnCooldownComplete(ASlasherPlayer* killer);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnChargeComplete();

private:
	UFUNCTION()
	void Authority_OnKillerTeleportPointSpawn(FGameplayTag gameEventType, const FGameEventData& gameEventData);

public:
	UK35KillerShootAreaBlastTravelProjectileChargeableInteractionDefinition();
};

FORCEINLINE uint32 GetTypeHash(const UK35KillerShootAreaBlastTravelProjectileChargeableInteractionDefinition) { return 0; }
