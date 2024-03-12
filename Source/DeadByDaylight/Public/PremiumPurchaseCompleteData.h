#pragma once

#include "CoreMinimal.h"
#include "PremiumPurchasedItemData.h"
#include "PremiumPurchaseCompleteData.generated.h"

USTRUCT(BlueprintType)
struct FPremiumPurchaseCompleteData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	TArray<FPremiumPurchasedItemData> PurchasedItems;

public:
	DEADBYDAYLIGHT_API FPremiumPurchaseCompleteData();
};

FORCEINLINE uint32 GetTypeHash(const FPremiumPurchaseCompleteData) { return 0; }
