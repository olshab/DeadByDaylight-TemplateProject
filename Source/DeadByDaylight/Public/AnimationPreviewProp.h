#pragma once

#include "CoreMinimal.h"
#include "AnimationPreviewProp.generated.h"

class AActor;

USTRUCT()
struct FAnimationPreviewProp
{
	GENERATED_BODY()

public:
	UPROPERTY()
	AActor* SpawnedProp;

public:
	DEADBYDAYLIGHT_API FAnimationPreviewProp();
};

FORCEINLINE uint32 GetTypeHash(const FAnimationPreviewProp) { return 0; }
