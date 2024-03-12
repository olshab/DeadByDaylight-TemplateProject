#pragma once

#include "CoreMinimal.h"
#include "Perk.h"
#include "Templates/SubclassOf.h"
#include "K35P02.generated.h"

class UTerrorRadiusEmitterComponent;
class UStatusEffect;

UCLASS(meta=(BlueprintSpawnableComponent))
class UK35P02 : public UPerk
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export)
	UTerrorRadiusEmitterComponent* _generatorTerrorRadiusEmitter;

	UPROPERTY(Transient, Export)
	UStatusEffect* _undetectableStatusEffect;

	UPROPERTY(EditDefaultsOnly, EditFixedSize)
	float _activePerkDuration;

	UPROPERTY(EditDefaultsOnly, EditFixedSize)
	float _cooldownDuration;

	UPROPERTY(EditDefaultsOnly, EditFixedSize)
	float _terrorRadiusSize;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _undetectableStatusEffectClass;

public:
	UK35P02();
};

FORCEINLINE uint32 GetTypeHash(const UK35P02) { return 0; }
