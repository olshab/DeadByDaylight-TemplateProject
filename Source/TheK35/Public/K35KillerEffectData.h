#pragma once

#include "CoreMinimal.h"
#include "K35KillerEffectData.generated.h"

class ACamperPlayer;

USTRUCT(BlueprintType)
struct FK35KillerEffectData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	ACamperPlayer* OwningSurvivor;

	UPROPERTY(BlueprintReadOnly)
	bool IsAffected;

	UPROPERTY(BlueprintReadOnly)
	float RemovalProgress;

	UPROPERTY(BlueprintReadOnly)
	bool HadSightLastTick;

public:
	THEK35_API FK35KillerEffectData();
};

FORCEINLINE uint32 GetTypeHash(const FK35KillerEffectData) { return 0; }
