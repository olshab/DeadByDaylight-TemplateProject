#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoreRecommendationCustomizationItemsRuntimeData.h"
#include "StoreRecommendationCustomizationRuntimeData.generated.h"

USTRUCT()
struct FStoreRecommendationCustomizationRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FDateTime ActiveFrom;

	UPROPERTY(Transient)
	FDateTime ActiveTo;

	UPROPERTY(Transient)
	TArray<FString> CategoryPriorities;

	UPROPERTY(Transient)
	TArray<FStoreRecommendationCustomizationItemsRuntimeData> Recommendations;

public:
	DEADBYDAYLIGHT_API FStoreRecommendationCustomizationRuntimeData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreRecommendationCustomizationRuntimeData) { return 0; }
