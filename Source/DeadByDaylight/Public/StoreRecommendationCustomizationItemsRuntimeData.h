#pragma once

#include "CoreMinimal.h"
#include "StoreRecommendationCustomizationItemsRuntimeData.generated.h"

USTRUCT()
struct FStoreRecommendationCustomizationItemsRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FString Category;

	UPROPERTY(Transient)
	TArray<FName> IDs;

public:
	DEADBYDAYLIGHT_API FStoreRecommendationCustomizationItemsRuntimeData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreRecommendationCustomizationItemsRuntimeData) { return 0; }
