#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "K35KillerTeleportPointInteractable.generated.h"

UCLASS()
class AK35KillerTeleportPointInteractable : public AInteractable
{
	GENERATED_BODY()

public:
	AK35KillerTeleportPointInteractable();
};

FORCEINLINE uint32 GetTypeHash(const AK35KillerTeleportPointInteractable) { return 0; }
