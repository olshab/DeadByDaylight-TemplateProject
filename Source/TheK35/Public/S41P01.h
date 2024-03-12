#pragma once

#include "CoreMinimal.h"
#include "ImposeStatusEffectSeancePerk.h"
#include "S41P01.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class US41P01 : public UImposeStatusEffectSeancePerk
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	float _instantChargesGained;

public:
	US41P01();
};

FORCEINLINE uint32 GetTypeHash(const US41P01) { return 0; }
