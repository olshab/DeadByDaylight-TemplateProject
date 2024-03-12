#pragma once

#include "CoreMinimal.h"
#include "PathStrategy_Flee.h"
#include "PathStrategy_FleeReposition.generated.h"

UCLASS(EditInlineNew)
class DBDBOTS_API UPathStrategy_FleeReposition : public UPathStrategy_Flee
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float WiggleOutRangeToKiller;

public:
	UPathStrategy_FleeReposition();
};

FORCEINLINE uint32 GetTypeHash(const UPathStrategy_FleeReposition) { return 0; }
