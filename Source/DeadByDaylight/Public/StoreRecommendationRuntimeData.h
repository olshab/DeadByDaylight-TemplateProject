#pragma once

#include "CoreMinimal.h"
#include "StoreRecommendationCustomizationRuntimeData.h"
#include "StoreFeaturedCharacterRecommendationData.h"
#include "StoreFeaturedChapterPackRecommendationData.h"
#include "StoreRecommendationRuntimeData.generated.h"

USTRUCT()
struct FStoreRecommendationRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FStoreRecommendationCustomizationRuntimeData> FeaturedCustomizationRecommendations;

	UPROPERTY(Transient)
	TArray<FStoreFeaturedCharacterRecommendationData> FeaturedCharacterRecommendations;

	UPROPERTY(Transient)
	TArray<FStoreFeaturedChapterPackRecommendationData> FeaturedChapterPackRecommendations;

	UPROPERTY(Transient)
	TArray<FStoreRecommendationCustomizationRuntimeData> SpecialsRecommendations;

public:
	DEADBYDAYLIGHT_API FStoreRecommendationRuntimeData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreRecommendationRuntimeData) { return 0; }
