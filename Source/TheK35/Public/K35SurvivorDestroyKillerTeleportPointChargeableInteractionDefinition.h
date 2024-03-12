#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ChargeableInteractionDefinition.h"
#include "DBDTunableRowHandle.h"
#include "K35SurvivorDestroyKillerTeleportPointChargeableInteractionDefinition.generated.h"

class ACamperPlayer;
class UStatusEffect;
class AK35KillerTeleportPoint;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UK35SurvivorDestroyKillerTeleportPointChargeableInteractionDefinition : public UChargeableInteractionDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	float _horizontalDestroyCheckDistance;

	UPROPERTY(EditDefaultsOnly)
	float _verticalDestroyCheckDistance;

	UPROPERTY(EditDefaultsOnly)
	float _cameraCheckSphereRadius;

	UPROPERTY(EditDefaultsOnly)
	float _lineOfSightCheckSphereRadius;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _killerInstinctStatusEffect;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _failureKillerInstinctDuration;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _secondsToCharge;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _interactionDistance;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _gracePeriodPercentage;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _successPercentage;

	UPROPERTY(EditDefaultsOnly)
	float _lineOfSightCollisionSize;

private:
	UFUNCTION()
	void OnIntroCompleted();

public:
	UFUNCTION(BlueprintPure)
	AK35KillerTeleportPoint* GetOwningKillerTeleportPoint() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorStartInteraction(const ACamperPlayer* survivor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorFinishedInteraction(const ACamperPlayer* survivor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorCancelledInteractionDuringGracePeriod(const ACamperPlayer* survivor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorCancelledInteraction(const ACamperPlayer* survivor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnInteractionNoLongerAvailable(const ACamperPlayer* survivor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnInteractionAvailable(const ACamperPlayer* survivor);

public:
	UK35SurvivorDestroyKillerTeleportPointChargeableInteractionDefinition();
};

FORCEINLINE uint32 GetTypeHash(const UK35SurvivorDestroyKillerTeleportPointChargeableInteractionDefinition) { return 0; }
