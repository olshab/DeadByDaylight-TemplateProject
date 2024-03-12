#pragma once

#include "CoreMinimal.h"
#include "ERewardType.h"
#include "EProgressionType.h"
#include "ECurrencyType.h"
#include "MysteryBoxClaimedReward.generated.h"

USTRUCT()
struct FMysteryBoxClaimedReward
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	ERewardType Type;

	UPROPERTY(Transient)
	ECurrencyType Currency;

	UPROPERTY(Transient)
	bool Currency_IsSet;

	UPROPERTY(Transient)
	EProgressionType Progression;

	UPROPERTY(Transient)
	bool Progression_IsSet;

	UPROPERTY(Transient)
	int32 Amount;

	UPROPERTY(Transient)
	bool Amount_IsSet;

public:
	DEADBYDAYLIGHT_API FMysteryBoxClaimedReward();
};

FORCEINLINE uint32 GetTypeHash(const FMysteryBoxClaimedReward) { return 0; }
