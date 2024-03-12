#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "EMultiImposeEffectTo.h"
#include "MultiStatusEffectInfo.generated.h"

class UStatusEffect;

USTRUCT(BlueprintType)
struct FMultiStatusEffectInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag EventTrigger;

	UPROPERTY(EditDefaultsOnly)
	bool RequireEventInstigatorToMatchAddonOwnerToImposeStatusEffects;

	UPROPERTY(EditDefaultsOnly)
	bool RequireEventTargetToMatchAddonOwnerToImposeStatusEffects;

	UPROPERTY(EditDefaultsOnly)
	float StatusEffectLifetime;

	UPROPERTY(EditDefaultsOnly)
	float CustomParamValue;

	UPROPERTY(EditDefaultsOnly)
	EMultiImposeEffectTo ImposeEffectTo;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> StatusEffect;

public:
	DBDCOMPETENCE_API FMultiStatusEffectInfo();
};

FORCEINLINE uint32 GetTypeHash(const FMultiStatusEffectInfo) { return 0; }
