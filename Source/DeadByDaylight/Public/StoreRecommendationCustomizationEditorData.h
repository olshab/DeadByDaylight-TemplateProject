#pragma once

#include "CoreMinimal.h"
#include "DBDTableRowBase.h"
#include "UObject/NoExportTypes.h"
#include "StoreRecommendationCustomizationEditorData.generated.h"

USTRUCT()
struct FStoreRecommendationCustomizationEditorData: public FDBDTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FDateTime ActiveFrom;

	UPROPERTY(EditAnywhere)
	FDateTime ActiveTo;

	UPROPERTY(EditAnywhere)
	TArray<FString> Outfits;

	UPROPERTY(EditAnywhere)
	TArray<FString> Items;

	UPROPERTY(EditAnywhere)
	TArray<FString> RecommendedCategoriesPriority;

public:
	DEADBYDAYLIGHT_API FStoreRecommendationCustomizationEditorData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreRecommendationCustomizationEditorData) { return 0; }
