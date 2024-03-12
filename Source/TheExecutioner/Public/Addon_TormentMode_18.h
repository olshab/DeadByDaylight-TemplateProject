#pragma once

#include "CoreMinimal.h"
#include "ItemAddon.h"
#include "Templates/SubclassOf.h"
#include "Addon_TormentMode_18.generated.h"

class UStatusEffect;

UCLASS(meta=(BlueprintSpawnableComponent))
class UAddon_TormentMode_18 : public UItemAddon
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _mangledEffectClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _hemorrhageEffectClass;

	UPROPERTY(EditDefaultsOnly)
	float _mangledHemorrhageEffectLifetime;

public:
	UAddon_TormentMode_18();
};

FORCEINLINE uint32 GetTypeHash(const UAddon_TormentMode_18) { return 0; }
