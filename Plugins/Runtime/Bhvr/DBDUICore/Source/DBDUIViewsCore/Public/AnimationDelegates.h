#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnimationDelegates.generated.h"

UCLASS()
class UAnimationDelegates : public UObject
{
	GENERATED_BODY()

public:
	UAnimationDelegates();
};

FORCEINLINE uint32 GetTypeHash(const UAnimationDelegates) { return 0; }
