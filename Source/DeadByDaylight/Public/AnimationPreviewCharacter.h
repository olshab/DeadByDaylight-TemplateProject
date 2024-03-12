#pragma once

#include "CoreMinimal.h"
#include "EPlayerRole.h"
#include "AnimationPreviewCharacter.generated.h"

class APawn;

USTRUCT()
struct FAnimationPreviewCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EPlayerRole Role;

	UPROPERTY()
	APawn* SpawnedCharacter;

public:
	DEADBYDAYLIGHT_API FAnimationPreviewCharacter();
};

FORCEINLINE uint32 GetTypeHash(const FAnimationPreviewCharacter) { return 0; }
