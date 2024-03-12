#pragma once

#include "CoreMinimal.h"
#include "OnLevelReadyToPlayBaseMutator.h"
#include "OverrideGeneratorMaxChargeMutator.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UOverrideGeneratorMaxChargeMutator : public UOnLevelReadyToPlayBaseMutator
{
	GENERATED_BODY()

public:
	UOverrideGeneratorMaxChargeMutator();
};

FORCEINLINE uint32 GetTypeHash(const UOverrideGeneratorMaxChargeMutator) { return 0; }
