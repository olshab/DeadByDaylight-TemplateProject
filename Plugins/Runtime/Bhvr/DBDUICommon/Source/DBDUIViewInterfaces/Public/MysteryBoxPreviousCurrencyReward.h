#pragma once

#include "CoreMinimal.h"
#include "MysteryBoxPreviousReward.h"
#include "ECurrencyType.h"
#include "MysteryBoxPreviousCurrencyReward.generated.h"

UCLASS()
class DBDUIVIEWINTERFACES_API UMysteryBoxPreviousCurrencyReward : public UMysteryBoxPreviousReward
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	ECurrencyType Currency;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	int32 Amount;

public:
	UMysteryBoxPreviousCurrencyReward();
};

FORCEINLINE uint32 GetTypeHash(const UMysteryBoxPreviousCurrencyReward) { return 0; }
