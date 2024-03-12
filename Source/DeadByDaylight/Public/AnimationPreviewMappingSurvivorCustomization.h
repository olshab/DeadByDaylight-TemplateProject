#pragma once

#include "CoreMinimal.h"
#include "AnimationPreviewMappingSurvivorCustomization.generated.h"

USTRUCT()
struct FAnimationPreviewMappingSurvivorCustomization
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName Head;

	UPROPERTY(EditAnywhere)
	FName Torso;

	UPROPERTY(EditAnywhere)
	FName Legs;

public:
	DEADBYDAYLIGHT_API FAnimationPreviewMappingSurvivorCustomization();
};

FORCEINLINE uint32 GetTypeHash(const FAnimationPreviewMappingSurvivorCustomization) { return 0; }
