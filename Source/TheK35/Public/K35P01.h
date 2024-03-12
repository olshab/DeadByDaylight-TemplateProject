#pragma once

#include "CoreMinimal.h"
#include "Perk.h"
#include "Templates/SubclassOf.h"
#include "K35P01.generated.h"

class UStatusEffect;

UCLASS(meta=(BlueprintSpawnableComponent))
class UK35P01 : public UPerk
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	float _activeTime;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _timedHasteEffectClass;

	UPROPERTY(EditDefaultsOnly)
	float _hasteStatusEffectDuration;

	UPROPERTY(EditDefaultsOnly)
	float _hasteAmount;

public:
	UK35P01();
};

FORCEINLINE uint32 GetTypeHash(const UK35P01) { return 0; }
