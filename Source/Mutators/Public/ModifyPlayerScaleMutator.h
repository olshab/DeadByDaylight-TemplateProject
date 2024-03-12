#pragma once

#include "CoreMinimal.h"
#include "GameplayMutator.h"
#include "Templates/SubclassOf.h"
#include "ModifyPlayerScaleMutator.generated.h"

class UStatusEffect;

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class UModifyPlayerScaleMutator : public UGameplayMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _modifyLocomotionRateEffectClass;

	UPROPERTY(EditDefaultsOnly)
	float _locomotionSpeedRatio;

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ModifyScale(float scale);

public:
	UModifyPlayerScaleMutator();
};

FORCEINLINE uint32 GetTypeHash(const UModifyPlayerScaleMutator) { return 0; }
