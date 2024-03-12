#pragma once

#include "CoreMinimal.h"
#include "GameplayMutator.h"
#include "ForceHookStageMutator.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class MUTATORS_API UForceHookStageMutator : public UGameplayMutator
{
	GENERATED_BODY()

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetHookStage(int32 stage);

public:
	UForceHookStageMutator();
};

FORCEINLINE uint32 GetTypeHash(const UForceHookStageMutator) { return 0; }
