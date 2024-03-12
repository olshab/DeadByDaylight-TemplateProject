#pragma once

#include "CoreMinimal.h"
#include "ChargeableInteractionDefinition.h"
#include "CamperHealResult.h"
#include "HealInteraction.generated.h"

class ADBDPlayer;
class ACamperPlayer;
class AActor;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class DBDINTERACTION_API UHealInteraction : public UChargeableInteractionDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	ADBDPlayer* _healingPlayer;

protected:
	UFUNCTION(BlueprintPure)
	bool HasChargedMedkit(const ADBDPlayer* player) const;

	UFUNCTION(BlueprintPure)
	ACamperPlayer* GetTargetSurvivor() const;

	UFUNCTION(BlueprintPure)
	float GetHealScorePercent(float delta) const;

private:
	UFUNCTION()
	void Authority_OnSurvivorHealed(const FCamperHealResult& healResult);

protected:
	UFUNCTION(BlueprintNativeEvent)
	void Authority_OnPlayerHealed(ADBDPlayer* healingPlayer, ADBDPlayer* healedPlayer);

	UFUNCTION(BlueprintNativeEvent)
	void Authority_OnHealChargeApplied(float individualChargeAmount, float totalChargeAmount, AActor* chargeInstigator, bool wasCoop, float deltaTime);

public:
	UHealInteraction();
};

FORCEINLINE uint32 GetTypeHash(const UHealInteraction) { return 0; }
