#pragma once

#include "CoreMinimal.h"
#include "ItemAddon.h"
#include "Addon_TheBlight_BaseForceMaxToken.generated.h"

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class UAddon_TheBlight_BaseForceMaxToken : public UItemAddon
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	uint8 _overridenMaxDashToken;

public:
	UAddon_TheBlight_BaseForceMaxToken();
};

FORCEINLINE uint32 GetTypeHash(const UAddon_TheBlight_BaseForceMaxToken) { return 0; }
