#pragma once

#include "CoreMinimal.h"
#include "BloodTrailComponent.h"
#include "DBDTunableRowHandle.h"
#include "ECamperDamageState.h"
#include "Spring2024MapBloodTrailComponent.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class USpring2024MapBloodTrailComponent : public UBloodTrailComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodTrailSpawnFrequencyTunable;

private:
	UFUNCTION()
	void OnCarryingPlayerHealthChange(ECamperDamageState oldDamageState, ECamperDamageState newDamageState);

public:
	USpring2024MapBloodTrailComponent();
};

FORCEINLINE uint32 GetTypeHash(const USpring2024MapBloodTrailComponent) { return 0; }
