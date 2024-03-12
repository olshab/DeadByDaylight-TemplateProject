#pragma once

#include "CoreMinimal.h"
#include "CurrencyProgressionTooltipViewData.h"
#include "StoreArchiveFragmentViewData.generated.h"

USTRUCT(BlueprintType)
struct FStoreArchiveFragmentViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient)
	FString Id;

	UPROPERTY(BlueprintReadWrite, Transient)
	FName ArchiveId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient)
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient)
	FCurrencyProgressionTooltipViewData TooltipData;

public:
	DBDUIVIEWINTERFACES_API FStoreArchiveFragmentViewData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreArchiveFragmentViewData) { return 0; }
