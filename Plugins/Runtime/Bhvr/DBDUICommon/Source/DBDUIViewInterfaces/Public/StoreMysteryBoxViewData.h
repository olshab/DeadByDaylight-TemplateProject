#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoreMysteryBoxViewData.generated.h"

class UMysteryBoxPreviousReward;

USTRUCT(BlueprintType)
struct FStoreMysteryBoxViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool CanClaimCurrentBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool HasNextBoxToClaim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FDateTime NextAvailableAtTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool HasPreviousClaimedBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FDateTime PreviousClaimTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	UMysteryBoxPreviousReward* Reward;

public:
	DBDUIVIEWINTERFACES_API FStoreMysteryBoxViewData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreMysteryBoxViewData) { return 0; }
