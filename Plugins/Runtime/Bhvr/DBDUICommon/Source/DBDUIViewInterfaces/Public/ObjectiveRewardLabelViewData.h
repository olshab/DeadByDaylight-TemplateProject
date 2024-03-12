#pragma once

#include "CoreMinimal.h"
#include "EventObjectiveTargetData.h"
#include "ECurrencyType.h"
#include "ObjectiveRewardLabelViewData.generated.h"

USTRUCT(BlueprintType)
struct FObjectiveRewardLabelViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient)
	FEventObjectiveTargetData TargetData;

	UPROPERTY(BlueprintReadWrite, Transient)
	ECurrencyType CurrencyRewardType;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool IsReached;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool IsActive;

public:
	DBDUIVIEWINTERFACES_API FObjectiveRewardLabelViewData();
};

FORCEINLINE uint32 GetTypeHash(const FObjectiveRewardLabelViewData) { return 0; }
