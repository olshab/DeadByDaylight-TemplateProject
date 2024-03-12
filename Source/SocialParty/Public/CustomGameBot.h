#pragma once

#include "CoreMinimal.h"
#include "Loadout.h"
#include "CustomGameBot.generated.h"

USTRUCT(BlueprintType)
struct FCustomGameBot
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint8 role;

	UPROPERTY()
	uint8 diff;

	UPROPERTY()
	int32 charIdx;

	UPROPERTY()
	int32 slotIdx;

	UPROPERTY()
	FString GUID;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FLoadout loadout;

public:
	SOCIALPARTY_API FCustomGameBot();
};

FORCEINLINE uint32 GetTypeHash(const FCustomGameBot) { return 0; }
