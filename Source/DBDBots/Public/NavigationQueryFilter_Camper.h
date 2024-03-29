#pragma once

#include "CoreMinimal.h"
#include "NavigationQueryFilter_Player.h"
#include "NavigationQueryFilter_Camper.generated.h"

UCLASS()
class DBDBOTS_API UNavigationQueryFilter_Camper : public UNavigationQueryFilter_Player
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	bool IgnoreOnAttackCooldown;

	UPROPERTY(EditDefaultsOnly)
	float SlasherAreaBoundsLimit;

	UPROPERTY(EditDefaultsOnly)
	float SlasherAreaPenetrationCost;

	UPROPERTY(EditDefaultsOnly)
	float SlasherInSightCost;

	UPROPERTY(EditDefaultsOnly)
	float SlasherAreaExcludeUnderRange;

	UPROPERTY(EditDefaultsOnly)
	float SlasherAreaUnwalkableRange;

	UPROPERTY(EditDefaultsOnly)
	float SlasherInExcludeAreaCost;

public:
	UNavigationQueryFilter_Camper();
};

FORCEINLINE uint32 GetTypeHash(const UNavigationQueryFilter_Camper) { return 0; }
