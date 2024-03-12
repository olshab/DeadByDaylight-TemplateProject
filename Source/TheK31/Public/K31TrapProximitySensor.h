#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "K31TrapProximitySensor.generated.h"

class ADBDPlayer;

UCLASS(meta=(BlueprintSpawnableComponent))
class THEK31_API UK31TrapProximitySensor : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TSet<ADBDPlayer*> _trappedPlayersInZone;

public:
	UK31TrapProximitySensor();
};

FORCEINLINE uint32 GetTypeHash(const UK31TrapProximitySensor) { return 0; }
