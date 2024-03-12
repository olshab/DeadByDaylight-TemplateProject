#pragma once

#include "CoreMinimal.h"
#include "AISkill_FindInteractable.h"
#include "KillerFilterItem.h"
#include "Templates/SubclassOf.h"
#include "AITunableParameter.h"
#include "PerkIdDropdown.h"
#include "AISkill_FindInteractable_SeanceSpot.generated.h"

class AActor;

UCLASS(EditInlineNew)
class DBDBOTS_API UAISkill_FindInteractable_SeanceSpot : public UAISkill_FindInteractable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FKillerFilterItem> LowerExposedValueKillers;

	UPROPERTY(EditDefaultsOnly)
	TArray<FKillerFilterItem> DirectTeleportKillers;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AActor>> TeleportInteractables;

	UPROPERTY(EditDefaultsOnly)
	FPerkIdDropdown NoMitherPerk;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter PerHookWeight;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter LowerExposedValueWeight;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter TeleportKillerWeightPenalty;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter KillerDistanceMaxWeight;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter KillerMaxDistance;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter KillerInChaseWeight;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter KillerMovingAwayWeight;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter KillerMovingAwayMaxAngle;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter LastSeenWeightPenalty;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter LastSeenMaxTime;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter LastVisitedWeightPenalty;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter LastVisitedMaxTime;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter JoinBaseWeight;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter JoinWithPerkWeight;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter SeanceOriginatorWeight;

private:
	UFUNCTION()
	void OnLevelReadyToPlay();

public:
	UAISkill_FindInteractable_SeanceSpot();
};

FORCEINLINE uint32 GetTypeHash(const UAISkill_FindInteractable_SeanceSpot) { return 0; }
