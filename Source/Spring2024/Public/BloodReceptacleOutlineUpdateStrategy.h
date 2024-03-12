#pragma once

#include "CoreMinimal.h"
#include "OutlineUpdateStrategy.h"
#include "DBDTunableRowHandle.h"
#include "EOfferingEffectType.h"
#include "UObject/NoExportTypes.h"
#include "BloodReceptacleOutlineUpdateStrategy.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UBloodReceptacleOutlineUpdateStrategy : public UOutlineUpdateStrategy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _revealTimeExtensionWithOffering;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _baseRevealTime;

	UPROPERTY(EditDefaultsOnly)
	EOfferingEffectType _offeringEffectTypeNeeded;

	UPROPERTY(EditDefaultsOnly)
	FLinearColor _outlineColor;

private:
	UFUNCTION()
	void OnIntroComplete();

public:
	UBloodReceptacleOutlineUpdateStrategy();
};

FORCEINLINE uint32 GetTypeHash(const UBloodReceptacleOutlineUpdateStrategy) { return 0; }
