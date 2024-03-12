#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DBDTunableRowHandle.h"
#include "Components/ActorComponent.h"
#include "TunableStat.h"
#include "GameEventData.h"
#include "K35KillerTeleportPointSpawningManager.generated.h"

class AK35KillerTeleportPoint;
class ASlasherPlayer;
class UCurveFloat;

UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class UK35KillerTeleportPointSpawningManager : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _maximumChargeTime;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _chargeTimerReductionMultiplierOnManuallyDestroyingKillerTeleportPoint;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _spawnTime;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _spawnTimeReductionOnSurvivorHookedWithKillerTeleportPointNearby;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _spawnTimeReductionOnInjuredSurvivorWithKillerEffect;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _addon16SpawnTimeReductionOnWallOrPalletBreakPercentage;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _spawnTimeReductionOnAfflictedSurvivorWithKillerEffect;

	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* _spawnTimeMultiplierBySurvivorsAffectedWithKillerEffectCurve;

private:
	UFUNCTION()
	void OnSurvivorInjuredWithKillerEffect(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void OnSurvivorAfflictedWithKillerEffect(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void OnKillerSet(ASlasherPlayer* killer);

	UFUNCTION()
	void OnKillerManuallyDestroyedKillerTeleportPoint(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void OnIntroCompleted();

	UFUNCTION()
	void OnGeneratorFixed(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void OnBreakWallOrPallet(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnSpawningStarted();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnSpawningComplete(AK35KillerTeleportPoint* acquiredTeleportPoint);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnSpawningCancelled();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnHookCausedRecycle();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnChargingStarted();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnChargingComplete();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_CompleteChargingTime();

public:
	UFUNCTION(BlueprintPure)
	bool IsSpawnTimerActive() const;

	UFUNCTION(BlueprintPure)
	bool IsChargeTimerActive() const;

	UFUNCTION(BlueprintPure)
	bool IsAbleToSpawnKillerTeleportPoint() const;

	UFUNCTION(BlueprintPure)
	float GetSpawnTimerProgress() const;

	UFUNCTION(BlueprintPure)
	float GetChargeTimerProgress() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSpawningStarted(const ASlasherPlayer* killer);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSpawningCancelled(const ASlasherPlayer* killer);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSpawnComplete(const ASlasherPlayer* killer, const AK35KillerTeleportPoint* acquiredTeleportPoint);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnChargingStarted(const ASlasherPlayer* killer);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnChargingComplete(const ASlasherPlayer* killer, const bool isSpawningPossible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnChargeTimerReduced(const ASlasherPlayer* killer);

private:
	UFUNCTION()
	void Authority_OnSurvivorHookedChanged(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void Authority_OnSpawnTimerEnded();

public:
	UK35KillerTeleportPointSpawningManager();
};

FORCEINLINE uint32 GetTypeHash(const UK35KillerTeleportPointSpawningManager) { return 0; }
