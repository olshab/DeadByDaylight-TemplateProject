#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "K35KillerTeleportPointPlacementValidatorComponent.generated.h"

class UObjectPlacementValidationWithRestrictionStrategy;

UCLASS(meta=(BlueprintSpawnableComponent))
class UK35KillerTeleportPointPlacementValidatorComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Export)
	UObjectPlacementValidationWithRestrictionStrategy* _objectPlacementValidationStrategyWithRestrictions;

public:
	UK35KillerTeleportPointPlacementValidatorComponent();
};

FORCEINLINE uint32 GetTypeHash(const UK35KillerTeleportPointPlacementValidatorComponent) { return 0; }
