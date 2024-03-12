#pragma once

#include "CoreMinimal.h"
#include "AnyActorPairQueryRangeIsTrue.h"
#include "TunableStat.h"
#include "OwningPlayerInK35KillerTeleportPointRange.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UOwningPlayerInK35KillerTeleportPointRange : public UAnyActorPairQueryRangeIsTrue
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	FTunableStat _killerTeleportPointRange;

private:
	UFUNCTION()
	void OnIntroComplete();

	UFUNCTION()
	void OnAcquiredKillerTeleportPointsChanged();

public:
	UOwningPlayerInK35KillerTeleportPointRange();
};

FORCEINLINE uint32 GetTypeHash(const UOwningPlayerInK35KillerTeleportPointRange) { return 0; }
