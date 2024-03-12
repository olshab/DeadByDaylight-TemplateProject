#pragma once

#include "CoreMinimal.h"
#include "ChargeableInteractionDefinition.h"
#include "SeanceRitualInteraction.generated.h"

class ADBDPlayer;
class ASeanceRitualSpot;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class DBDINTERACTION_API USeanceRitualInteraction : public UChargeableInteractionDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	float _nonPerkOwnerMultiplier;

public:
	UFUNCTION(BlueprintPure)
	bool IsInteractionPossibleInternal(const ADBDPlayer* player) const;

protected:
	UFUNCTION(BlueprintPure)
	ASeanceRitualSpot* GetOwningRitualSpot() const;

public:
	UFUNCTION(BlueprintPure)
	float GetInteractionChargeSpeedMultiplier_Implementation(const ADBDPlayer* character) const;

public:
	USeanceRitualInteraction();
};

FORCEINLINE uint32 GetTypeHash(const USeanceRitualInteraction) { return 0; }
