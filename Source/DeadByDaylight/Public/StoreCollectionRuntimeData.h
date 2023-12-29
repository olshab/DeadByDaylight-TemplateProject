#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EStoreCollectionFlags.h"
#include "StoreCollectionRuntimeData.generated.h"

USTRUCT()
struct FStoreCollectionRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FString CollectionId;

	UPROPERTY(Transient)
	FString InclusionVersion;

	UPROPERTY(Transient)
	TMap<FString, FString> CollectionTitleByCulture;

	UPROPERTY(Transient)
	TMap<FString, FString> CollectionSubtitleByCulture;

	UPROPERTY(Transient)
	FDateTime ActiveFrom;

	UPROPERTY(Transient)
	FDateTime ActiveTo;

	UPROPERTY(Transient)
	int32 SortOrder;

	UPROPERTY(Transient)
	FString HeroImage;

	UPROPERTY(Transient)
	FString HeroVideo;

	UPROPERTY(Transient)
	TArray<FString> AdditionalImages;

	UPROPERTY(Transient)
	TArray<FString> ItemIds;

	UPROPERTY(Transient)
	EStoreCollectionFlags Flags;

	UPROPERTY(Transient)
	FDateTime SpecialStartDate;

	UPROPERTY(Transient)
	FDateTime SpecialEndDate;

public:
	DEADBYDAYLIGHT_API FStoreCollectionRuntimeData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreCollectionRuntimeData) { return 0; }
