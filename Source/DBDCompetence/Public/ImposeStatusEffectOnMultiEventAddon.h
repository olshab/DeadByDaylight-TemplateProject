#pragma once

#include "CoreMinimal.h"
#include "ItemAddon.h"
#include "GameEventData.h"
#include "MultiStatusEffectInfo.h"
#include "GameplayTagContainer.h"
#include "ImposeStatusEffectOnMultiEventAddon.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class DBDCOMPETENCE_API UImposeStatusEffectOnMultiEventAddon : public UItemAddon
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	TArray<FMultiStatusEffectInfo> _statusEffectInfo;

private:
	UFUNCTION()
	void Authority_OnEventFired(const FGameplayTag gameEventTag, const FGameEventData& gameEventData);

public:
	UImposeStatusEffectOnMultiEventAddon();
};

FORCEINLINE uint32 GetTypeHash(const UImposeStatusEffectOnMultiEventAddon) { return 0; }
