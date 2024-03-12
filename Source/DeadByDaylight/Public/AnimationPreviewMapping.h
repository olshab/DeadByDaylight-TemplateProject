#pragma once

#include "CoreMinimal.h"
#include "DBDTableRowBase.h"
#include "EAnimationPreviewType.h"
#include "AnimationPreviewMappingSurvivorCustomization.h"
#include "AnimationPreviewMapping.generated.h"

USTRUCT()
struct FAnimationPreviewMapping: public FDBDTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FString MappingId;

	UPROPERTY(EditAnywhere)
	EAnimationPreviewType AnimationType;

	UPROPERTY(EditAnywhere)
	FName WhenKiller;

	UPROPERTY(EditAnywhere)
	FName UseSurvivor;

	UPROPERTY(EditAnywhere)
	FAnimationPreviewMappingSurvivorCustomization UseSurvivorCustomization;

public:
	DEADBYDAYLIGHT_API FAnimationPreviewMapping();
};

FORCEINLINE uint32 GetTypeHash(const FAnimationPreviewMapping) { return 0; }
