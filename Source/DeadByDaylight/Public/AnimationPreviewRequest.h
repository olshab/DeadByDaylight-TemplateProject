#pragma once

#include "CoreMinimal.h"
#include "EAnimationPreviewType.h"
#include "AnimationPreviewPropRequest.h"
#include "AnimationPreviewCharacterRequest.h"
#include "AnimationPreviewRequest.generated.h"

USTRUCT(BlueprintType)
struct FAnimationPreviewRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAnimationPreviewType Type;

	UPROPERTY()
	TArray<FAnimationPreviewCharacterRequest> CharactersToUse;

	UPROPERTY()
	TArray<FAnimationPreviewPropRequest> PropsToUse;

public:
	DEADBYDAYLIGHT_API FAnimationPreviewRequest();
};

FORCEINLINE uint32 GetTypeHash(const FAnimationPreviewRequest) { return 0; }
