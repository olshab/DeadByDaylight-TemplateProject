#pragma once

#include "CoreMinimal.h"
#include "EStoreSpecialPackItemType.h"
#include "StoreSpecialPackItem.generated.h"

USTRUCT(BlueprintType)
struct FStoreSpecialPackItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EStoreSpecialPackItemType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Amount;

public:
	DEADBYDAYLIGHT_API FStoreSpecialPackItem();
};

FORCEINLINE uint32 GetTypeHash(const FStoreSpecialPackItem) { return 0; }
