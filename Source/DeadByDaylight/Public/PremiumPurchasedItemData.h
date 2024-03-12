#pragma once

#include "CoreMinimal.h"
#include "PremiumPurchasedItemData.generated.h"

USTRUCT(BlueprintType)
struct FPremiumPurchasedItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FString Id;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FString Type;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	int32 Amount;

public:
	DEADBYDAYLIGHT_API FPremiumPurchasedItemData();
};

FORCEINLINE uint32 GetTypeHash(const FPremiumPurchasedItemData) { return 0; }
