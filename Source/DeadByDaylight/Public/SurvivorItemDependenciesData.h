#pragma once

#include "CoreMinimal.h"
#include "DBDTableRowBase.h"
#include "UObject/SoftObjectPtr.h"
#include "KillerItemProperty.h"
#include "SurvivorItemDependenciesData.generated.h"

class UBaseSpawnConditionStrategy;

USTRUCT()
struct FSurvivorItemDependenciesData: public FDBDTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UBaseSpawnConditionStrategy> SpawnConditionStrategyClass;

	UPROPERTY(EditAnywhere)
	TArray<FKillerItemProperty> Items;

public:
	DEADBYDAYLIGHT_API FSurvivorItemDependenciesData();
};

FORCEINLINE uint32 GetTypeHash(const FSurvivorItemDependenciesData) { return 0; }
