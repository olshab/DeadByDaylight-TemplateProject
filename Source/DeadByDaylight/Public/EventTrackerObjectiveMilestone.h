#pragma once

#include "CoreMinimal.h"
#include "EventTrackerObjectiveMilestone.generated.h"

USTRUCT()
struct FEventTrackerObjectiveMilestone
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float AdditiveMultiplier;

	UPROPERTY()
	int32 NeededProgression;

public:
	DEADBYDAYLIGHT_API FEventTrackerObjectiveMilestone();
};

FORCEINLINE uint32 GetTypeHash(const FEventTrackerObjectiveMilestone) { return 0; }
