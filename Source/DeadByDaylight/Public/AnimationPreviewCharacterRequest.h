#pragma once

#include "CoreMinimal.h"
#include "CharacterCustomization.h"
#include "EPlayerRole.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "AnimationPreviewCharacterRequest.generated.h"

class APawn;

USTRUCT(BlueprintType)
struct FAnimationPreviewCharacterRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EPlayerRole Role;

	UPROPERTY()
	TSoftClassPtr<APawn> CharacterClass;

	UPROPERTY()
	FCharacterCustomization Customization;

	UPROPERTY()
	FTransform SpawnTransform;

public:
	DEADBYDAYLIGHT_API FAnimationPreviewCharacterRequest();
};

FORCEINLINE uint32 GetTypeHash(const FAnimationPreviewCharacterRequest) { return 0; }
