#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MysteryBoxClaimedReward.h"
#include "MysteryBoxStatus.generated.h"

USTRUCT()
struct FMysteryBoxStatus
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, SkipSerialization)
	FString Campaign;

	UPROPERTY(Transient)
	bool CanClaimCurrentBox;

	UPROPERTY(Transient)
	FDateTime NextClaimTime;

	UPROPERTY(Transient, SkipSerialization)
	bool NextClaimTime_IsSet;

	UPROPERTY(Transient)
	FDateTime LastClaimTime;

	UPROPERTY(Transient, SkipSerialization)
	bool LastClaimTime_IsSet;

	UPROPERTY(Transient, SkipSerialization)
	TArray<FMysteryBoxClaimedReward> LastReward;

	UPROPERTY(Transient, SkipSerialization)
	bool LastReward_IsSet;

public:
	DEADBYDAYLIGHT_API FMysteryBoxStatus();
};

FORCEINLINE uint32 GetTypeHash(const FMysteryBoxStatus) { return 0; }
