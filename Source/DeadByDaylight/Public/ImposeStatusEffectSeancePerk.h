#pragma once

#include "CoreMinimal.h"
#include "SeancePerk.h"
#include "Templates/SubclassOf.h"
#include "ImposeStatusEffectSeancePerk.generated.h"

class UStatusEffect;

UCLASS(meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API UImposeStatusEffectSeancePerk : public USeancePerk
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float _effectAmount;

	UPROPERTY(EditDefaultsOnly)
	float _effectLifetime;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _statusEffectClass;

public:
	UImposeStatusEffectSeancePerk();
};

FORCEINLINE uint32 GetTypeHash(const UImposeStatusEffectSeancePerk) { return 0; }
