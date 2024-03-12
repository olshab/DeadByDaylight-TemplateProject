#pragma once

#include "CoreMinimal.h"
#include "EventTrackerQuestEventCondition.h"
#include "EventTrackerObjectiveMilestone.h"
#include "EventTrackerObjective.generated.h"

USTRUCT()
struct FEventTrackerObjective
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	int32 MaxProgressionPerMatchPlayer;

	UPROPERTY()
	FString QuestEventId;

	UPROPERTY()
	FString QuestEventParams;

	UPROPERTY()
	TArray<FEventTrackerQuestEventCondition> QuestEventConditions;

	UPROPERTY(SkipSerialization)
	bool QuestEventConditions_IsSet;

	UPROPERTY()
	TArray<FEventTrackerObjectiveMilestone> Milestones;

public:
	DEADBYDAYLIGHT_API FEventTrackerObjective();
};

FORCEINLINE uint32 GetTypeHash(const FEventTrackerObjective) { return 0; }
