#pragma once

#include "CoreMinimal.h"
#include "AITunableParameter.h"
#include "AISkill_Find.h"
#include "AISkill_Find_StrengthInShadows.generated.h"

UCLASS(EditInlineNew)
class DBDBOTS_API UAISkill_Find_StrengthInShadows : public UAISkill_Find
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter KillerDistanceMaxWeightPenalty;

	UPROPERTY(EditDefaultsOnly)
	FAITunableParameter KillerMaxDistance;

	UPROPERTY(EditDefaultsOnly)
	float BasementVerticalOffset;

private:
	UFUNCTION()
	void OnLevelReadyToPlay();

public:
	UAISkill_Find_StrengthInShadows();
};

FORCEINLINE uint32 GetTypeHash(const UAISkill_Find_StrengthInShadows) { return 0; }
