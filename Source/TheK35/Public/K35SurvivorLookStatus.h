#pragma once

#include "CoreMinimal.h"
#include "K35SurvivorLookStatus.generated.h"

class ACamperPlayer;

USTRUCT(BlueprintType)
struct FK35SurvivorLookStatus
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	ACamperPlayer* OwningSurvivor;

	UPROPERTY(BlueprintReadOnly)
	bool IsLookingAtKiller;

public:
	THEK35_API FK35SurvivorLookStatus();
};

FORCEINLINE uint32 GetTypeHash(const FK35SurvivorLookStatus) { return 0; }
