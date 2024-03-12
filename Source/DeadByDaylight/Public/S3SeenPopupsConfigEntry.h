#pragma once

#include "CoreMinimal.h"
#include "S3SeenPopupsConfigEntry.generated.h"

USTRUCT()
struct FS3SeenPopupsConfigEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	int32 MaxTimes;

	UPROPERTY()
	int32 MinLoginThreshold;

	UPROPERTY()
	int32 SessionsPerPopup;

public:
	DEADBYDAYLIGHT_API FS3SeenPopupsConfigEntry();
};

FORCEINLINE uint32 GetTypeHash(const FS3SeenPopupsConfigEntry) { return 0; }
