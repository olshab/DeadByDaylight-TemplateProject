#pragma once

#include "CoreMinimal.h"
#include "MysteryBoxPreviousReward.h"
#include "EProgressionType.h"
#include "MysteryBoxPreviousProgressionReward.generated.h"

UCLASS()
class DBDUIVIEWINTERFACES_API UMysteryBoxPreviousProgressionReward : public UMysteryBoxPreviousReward
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	EProgressionType Progression;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	int32 Amount;

public:
	UMysteryBoxPreviousProgressionReward();
};

FORCEINLINE uint32 GetTypeHash(const UMysteryBoxPreviousProgressionReward) { return 0; }
