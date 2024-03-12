#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ERewardType.h"
#include "MysteryBoxPreviousReward.generated.h"

UCLASS(BlueprintType)
class DBDUIVIEWINTERFACES_API UMysteryBoxPreviousReward : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	ERewardType Type;

public:
	UMysteryBoxPreviousReward();
};

FORCEINLINE uint32 GetTypeHash(const UMysteryBoxPreviousReward) { return 0; }
