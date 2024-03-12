#pragma once

#include "CoreMinimal.h"
#include "EventTrackerQuestEventCondition.generated.h"

USTRUCT()
struct FEventTrackerQuestEventCondition
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Key;

	UPROPERTY()
	TArray<FString> Value;

public:
	DEADBYDAYLIGHT_API FEventTrackerQuestEventCondition();
};

FORCEINLINE uint32 GetTypeHash(const FEventTrackerQuestEventCondition) { return 0; }
