#pragma once

#include "CoreMinimal.h"
#include "BhvrAssetViewCameraSequence.generated.h"

class ULevelSequence;
class ALevelSequenceActor;

USTRUCT(BlueprintType)
struct FBhvrAssetViewCameraSequence
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FString DisplayName;

	UPROPERTY(Transient)
	ULevelSequence* Sequence;

	UPROPERTY(Transient)
	ALevelSequenceActor* SequenceActor;

public:
	BHVRASSETVIEWER_API FBhvrAssetViewCameraSequence();
};

FORCEINLINE uint32 GetTypeHash(const FBhvrAssetViewCameraSequence) { return 0; }
