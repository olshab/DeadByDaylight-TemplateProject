#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SavedSeenPopupData.generated.h"

USTRUCT()
struct FSavedSeenPopupData
{
	GENERATED_BODY()

public:
	UPROPERTY(SaveGame)
	FDateTime LastSeenDate;

	UPROPERTY(SaveGame)
	int32 LastSeenCumulativeSession;

	UPROPERTY(SaveGame)
	int32 TimesSeen;

public:
	DEADBYDAYLIGHT_API FSavedSeenPopupData();
};

FORCEINLINE uint32 GetTypeHash(const FSavedSeenPopupData) { return 0; }
