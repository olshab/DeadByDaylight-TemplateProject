#pragma once

#include "CoreMinimal.h"
#include "RestrictedPlacementAreaStrategy.h"
#include "K35KillerTeleportPointPlacementValidationStrategy.generated.h"

UCLASS(EditInlineNew)
class UK35KillerTeleportPointPlacementValidationStrategy : public URestrictedPlacementAreaStrategy
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnKillerTeleportPointStateChanged();

	UFUNCTION()
	void OnIntroCompleted();

public:
	UK35KillerTeleportPointPlacementValidationStrategy();
};

FORCEINLINE uint32 GetTypeHash(const UK35KillerTeleportPointPlacementValidationStrategy) { return 0; }
