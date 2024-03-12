#pragma once

#include "CoreMinimal.h"
#include "ItemAddon.h"
#include "Templates/SubclassOf.h"
#include "Addon_Beartrap_RustedJaws.generated.h"

class UStatusEffect;

UCLASS(meta=(BlueprintSpawnableComponent))
class UAddon_Beartrap_RustedJaws : public UItemAddon
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _mangledEffectClass;

	UPROPERTY(EditDefaultsOnly)
	float _mangledEffectLifetime;

public:
	UAddon_Beartrap_RustedJaws();
};

FORCEINLINE uint32 GetTypeHash(const UAddon_Beartrap_RustedJaws) { return 0; }
