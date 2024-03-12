#pragma once

#include "CoreMinimal.h"
#include "GameplayMutator.h"
#include "OverrideGeneratorRequirementsMutator.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UOverrideGeneratorRequirementsMutator : public UGameplayMutator
{
	GENERATED_BODY()

public:
	UOverrideGeneratorRequirementsMutator();
};

FORCEINLINE uint32 GetTypeHash(const UOverrideGeneratorRequirementsMutator) { return 0; }
