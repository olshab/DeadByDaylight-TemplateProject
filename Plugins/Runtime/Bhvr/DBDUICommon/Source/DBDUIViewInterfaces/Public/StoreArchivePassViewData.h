#pragma once

#include "CoreMinimal.h"
#include "ArchivePassTooltipViewData.h"
#include "TimerFlagViewData.h"
#include "StoreArchivePassViewData.generated.h"

USTRUCT(BlueprintType)
struct FStoreArchivePassViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient)
	FString PassId;

	UPROPERTY(BlueprintReadWrite, Transient)
	FName ArchiveId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient)
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient)
	FText ArchiveTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient)
	FArchivePassTooltipViewData TooltipData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient)
	bool IsOwned;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient)
	FTimerFlagViewData TimerFlagViewData;

public:
	DBDUIVIEWINTERFACES_API FStoreArchivePassViewData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreArchivePassViewData) { return 0; }
