#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CakeModePlayerComponent.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UCakeModePlayerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCakeModePlayerComponent();
};

FORCEINLINE uint32 GetTypeHash(const UCakeModePlayerComponent) { return 0; }
