#pragma once

#include "CoreMinimal.h"
#include "AdjustableCooldownStatusEffect.h"
#include "MangledEffect.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class DBDCOMPETENCE_API UMangledEffect : public UAdjustableCooldownStatusEffect
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	bool _removeEffectWhenFullyHealed;

public:
	UMangledEffect();
};

FORCEINLINE uint32 GetTypeHash(const UMangledEffect) { return 0; }
