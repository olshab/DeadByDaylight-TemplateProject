#pragma once

#include "CoreMinimal.h"
#include "AnimationPreview.h"
#include "InteractionAnimationPreview.generated.h"

class UInteractionDefinition;
class ADBDPlayer;

UCLASS(Abstract)
class UInteractionAnimationPreview : public UAnimationPreview
{
	GENERATED_BODY()

private:
	UPROPERTY(Export)
	UInteractionDefinition* _interactionDefinition;

private:
	UFUNCTION()
	void OnInteractionFinished(ADBDPlayer* player, bool didInteractionStart);

public:
	UInteractionAnimationPreview();
};

FORCEINLINE uint32 GetTypeHash(const UInteractionAnimationPreview) { return 0; }
