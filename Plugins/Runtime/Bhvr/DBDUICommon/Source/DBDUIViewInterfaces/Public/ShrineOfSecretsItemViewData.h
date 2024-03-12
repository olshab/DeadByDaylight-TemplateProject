#pragma once

#include "CoreMinimal.h"
#include "LoadoutTooltipData.h"
#include "UObject/SoftObjectPtr.h"
#include "PriceTagViewData.h"
#include "ShrineOfSecretsItemViewData.generated.h"

class UMenuPerkViewData;
class UTexture2D;

USTRUCT(BlueprintType)
struct FShrineOfSecretsItemViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient)
	FName ItemId;

	UPROPERTY(BlueprintReadOnly, Transient)
	int32 BPCost;

	UPROPERTY(BlueprintReadOnly, Transient)
	UMenuPerkViewData* Perk;

	UPROPERTY(BlueprintReadOnly, Transient)
	FLoadoutTooltipData PerkTooltip;

	UPROPERTY(BlueprintReadOnly, Transient)
	FPriceTagViewData PriceTag;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool PerkMaxed;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool BPClaimed;

	UPROPERTY(BlueprintReadOnly, Transient)
	bool IsASurvivor;

	UPROPERTY(BlueprintReadOnly, Transient)
	TSoftObjectPtr<UTexture2D> Portrait;

public:
	DBDUIVIEWINTERFACES_API FShrineOfSecretsItemViewData();
};

FORCEINLINE uint32 GetTypeHash(const FShrineOfSecretsItemViewData) { return 0; }
