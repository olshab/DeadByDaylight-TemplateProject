#pragma once

#include "CoreMinimal.h"
#include "ERewardType.h"
#include "EProgressionType.h"
#include "ECurrencyType.h"
#include "MysteryBoxReward.generated.h"

USTRUCT()
struct FMysteryBoxReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	ERewardType Type;

	UPROPERTY(EditAnywhere)
	ECurrencyType CurrencyType;

	UPROPERTY(EditAnywhere)
	EProgressionType ProgressionType;

	UPROPERTY(EditAnywhere)
	int32 Amount;

	UPROPERTY(EditAnywhere)
	int32 Weighting;

public:
	DEADBYDAYLIGHT_API FMysteryBoxReward();
};

FORCEINLINE uint32 GetTypeHash(const FMysteryBoxReward) { return 0; }
