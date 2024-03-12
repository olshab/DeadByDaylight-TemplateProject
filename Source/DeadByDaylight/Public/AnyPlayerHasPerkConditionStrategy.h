#pragma once

#include "CoreMinimal.h"
#include "BaseSpawnConditionStrategy.h"
#include "PerkIdDropdown.h"
#include "EPlayerRole.h"
#include "AnyPlayerHasPerkConditionStrategy.generated.h"

UCLASS()
class DEADBYDAYLIGHT_API UAnyPlayerHasPerkConditionStrategy : public UBaseSpawnConditionStrategy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	EPlayerRole _playerRole;

	UPROPERTY(EditDefaultsOnly)
	FPerkIdDropdown _perk;

public:
	UAnyPlayerHasPerkConditionStrategy();
};

FORCEINLINE uint32 GetTypeHash(const UAnyPlayerHasPerkConditionStrategy) { return 0; }
