#pragma once

#include "CoreMinimal.h"
#include "InteractionDefinition.h"
#include "PickupInteraction.generated.h"

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UPickupInteraction : public UInteractionDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<FString> _nonOverrideableInteractionsOnTargetPlayer;

	UPROPERTY(EditDefaultsOnly)
	TArray<FString> _overrideableInteractions;

public:
	UPickupInteraction();
};

FORCEINLINE uint32 GetTypeHash(const UPickupInteraction) { return 0; }
