#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoreSpecialPackCatalogPrice.h"
#include "StoreSpecialPackCatalogItemMetaData.generated.h"

USTRUCT()
struct FStoreSpecialPackCatalogItemMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FStoreSpecialPackCatalogPrice> FullPrice;

	UPROPERTY(Transient)
	uint32 SortOrder;

	UPROPERTY(Transient)
	FString ImagePath;

	UPROPERTY(Transient)
	TMap<FString, FString> SpecialPackTitle;

	UPROPERTY(Transient)
	float Discount;

	UPROPERTY(Transient)
	FDateTime StartDate;

	UPROPERTY(Transient, SkipSerialization)
	bool StartDate_IsSet;

	UPROPERTY(Transient)
	FDateTime EndDate;

	UPROPERTY(Transient, SkipSerialization)
	bool EndDate_IsSet;

	UPROPERTY(Transient)
	FString DLCId;

	UPROPERTY(Transient, SkipSerialization)
	bool DLCId_IsSet;

public:
	DEADBYDAYLIGHT_API FStoreSpecialPackCatalogItemMetaData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreSpecialPackCatalogItemMetaData) { return 0; }
