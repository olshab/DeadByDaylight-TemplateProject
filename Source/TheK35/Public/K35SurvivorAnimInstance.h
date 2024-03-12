#pragma once

#include "CoreMinimal.h"
#include "BaseSurvivorAnimInstance.h"
#include "GameplayTagContainer.h"
#include "ECamperDamageState.h"
#include "GameEventData.h"
#include "K35SurvivorAnimInstance.generated.h"

UCLASS(NonTransient)
class UK35SurvivorAnimInstance : public UBaseSurvivorAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient)
	bool _isDestroyingKillerTeleportPoint;

	UPROPERTY(BlueprintReadOnly, Transient)
	float _huskDestructionHorizontalCameraOffset;

	UPROPERTY(BlueprintReadOnly, Transient)
	float _huskDestructionVerticalCameraOffset;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool _isAfflictedByKillerEffect;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool _isRespondingToKillerTeleportPointInterruptByTeleport;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool _isRespondingToInfection;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool _isRespondingToProjectileHindered;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool _isRespondingToAreaBlastInjury;

	UPROPERTY(BlueprintReadOnly, Transient)
	ECamperDamageState _damageState;

	UPROPERTY(EditDefaultsOnly)
	float _destroyLingerTime;

public:
	UFUNCTION(BlueprintCallable)
	void StartKillCam();

	UFUNCTION(BlueprintCallable)
	void ResetRespondingToProjectileHinderedEvent();

	UFUNCTION(BlueprintCallable)
	void ResetRespondingToInfectionEvent();

	UFUNCTION(BlueprintCallable)
	void ResetRespondingToAreaBlastInjuryEvent();

private:
	UFUNCTION()
	void OnGameEventReceived(const FGameplayTag gameplayTag, const FGameEventData& gameEventData);

public:
	UFUNCTION(BlueprintCallable)
	void EndKillCam();

public:
	UK35SurvivorAnimInstance();
};

FORCEINLINE uint32 GetTypeHash(const UK35SurvivorAnimInstance) { return 0; }
