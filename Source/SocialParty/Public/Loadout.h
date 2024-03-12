#pragma once

#include "CoreMinimal.h"
#include "Loadout.generated.h"

USTRUCT(BlueprintType)
struct FLoadout
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FName> data;

public:
	SOCIALPARTY_API FLoadout();
};

FORCEINLINE uint32 GetTypeHash(const FLoadout) { return 0; }
