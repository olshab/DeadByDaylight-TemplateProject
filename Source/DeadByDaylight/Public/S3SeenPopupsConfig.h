#pragma once

#include "CoreMinimal.h"
#include "S3SeenPopupsConfigEntry.h"
#include "S3SeenPopupsConfig.generated.h"

USTRUCT()
struct FS3SeenPopupsConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	TArray<FS3SeenPopupsConfigEntry> Configs;

public:
	DEADBYDAYLIGHT_API FS3SeenPopupsConfig();
};

FORCEINLINE uint32 GetTypeHash(const FS3SeenPopupsConfig) { return 0; }
