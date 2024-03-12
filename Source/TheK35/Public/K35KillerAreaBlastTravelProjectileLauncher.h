#pragma once

#include "CoreMinimal.h"
#include "KillerProjectileLauncher.h"
#include "DBDTunableRowHandle.h"
#include "K35KillerAreaBlastTravelProjectileLauncher.generated.h"

class UCurveFloat;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UK35KillerAreaBlastTravelProjectileLauncher : public UKillerProjectileLauncher
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _launchSpeed;

	UPROPERTY(EditDefaultsOnly)
	FName _spawnSocketName;

	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* _pitchCurve;

public:
	UK35KillerAreaBlastTravelProjectileLauncher();
};

FORCEINLINE uint32 GetTypeHash(const UK35KillerAreaBlastTravelProjectileLauncher) { return 0; }
