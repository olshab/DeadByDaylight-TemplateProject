#pragma once

#include "CoreMinimal.h"
#include "GameplayMutator.h"
#include "Templates/SubclassOf.h"
#include "PlayerSpawningEffectGameplayMutator.generated.h"

class UStatusEffect;

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class UPlayerSpawningEffectGameplayMutator : public UGameplayMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _statusEffectClass;

	UPROPERTY(EditDefaultsOnly)
	bool _shouldDisplay;

	UPROPERTY(EditDefaultsOnly)
	float _lifetime;

public:
	UPlayerSpawningEffectGameplayMutator();
};

FORCEINLINE uint32 GetTypeHash(const UPlayerSpawningEffectGameplayMutator) { return 0; }
