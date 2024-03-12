#pragma once

#include "CoreMinimal.h"
#include "CustomGameBotsData.h"
#include "CustomGamePresetData.generated.h"

USTRUCT()
struct FCustomGamePresetData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<uint8> mapAvails;

	UPROPERTY()
	bool perkAvail;

	UPROPERTY()
	bool offeringAvail;

	UPROPERTY()
	bool itemAvail;

	UPROPERTY()
	bool itemAddonAvail;

	UPROPERTY()
	bool dlcContentAllowed;

	UPROPERTY()
	bool privateMatch;

	UPROPERTY()
	FCustomGameBotsData bots;

public:
	SOCIALPARTY_API FCustomGamePresetData();
};

FORCEINLINE uint32 GetTypeHash(const FCustomGamePresetData) { return 0; }
