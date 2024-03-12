#pragma once

#include "CoreMinimal.h"
#include "ItemAddon.h"
#include "Templates/SubclassOf.h"
#include "Addon_ThePig_BaseStatusReverseBearTrap.generated.h"

class ADBDPlayer;
class UStatusEffect;

UCLASS(meta=(BlueprintSpawnableComponent))
class THEPIG_API UAddon_ThePig_BaseStatusReverseBearTrap : public UItemAddon
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _statusEffectClass;

private:
	UPROPERTY(Export)
	TMap<ADBDPlayer*, UStatusEffect*> _statusEffectPlayerMap;

public:
	UAddon_ThePig_BaseStatusReverseBearTrap();
};

FORCEINLINE uint32 GetTypeHash(const UAddon_ThePig_BaseStatusReverseBearTrap) { return 0; }
