#pragma once

#include "CoreMinimal.h"
#include "BhvrAssetViewOption.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FBhvrAssetViewOption
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FString Id;

	UPROPERTY(BlueprintReadOnly)
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* Thumbnail;

public:
	BHVRASSETVIEWER_API FBhvrAssetViewOption();
};

FORCEINLINE uint32 GetTypeHash(const FBhvrAssetViewOption) { return 0; }
