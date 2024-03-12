#pragma once

#include "CoreMinimal.h"
#include "GameplayMutator.h"
#include "OpenEscapeDoorOnGeneratorCompletionMutator.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UOpenEscapeDoorOnGeneratorCompletionMutator : public UGameplayMutator
{
	GENERATED_BODY()

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OpenEscapeDoors();

public:
	UOpenEscapeDoorOnGeneratorCompletionMutator();
};

FORCEINLINE uint32 GetTypeHash(const UOpenEscapeDoorOnGeneratorCompletionMutator) { return 0; }
