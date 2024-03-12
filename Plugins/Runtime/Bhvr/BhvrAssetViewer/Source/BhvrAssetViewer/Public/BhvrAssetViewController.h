#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AssetViewControllerLoadingStateChanged.h"
#include "BhvrAssetViewController.generated.h"

UCLASS(BlueprintType, Abstract, Transient)
class BHVRASSETVIEWER_API UBhvrAssetViewController : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FAssetViewControllerLoadingStateChanged LoadingStateChanged;

private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	bool bIsLoading;

public:
	UFUNCTION(BlueprintPure)
	bool IsLoading() const;

public:
	UBhvrAssetViewController();
};

FORCEINLINE uint32 GetTypeHash(const UBhvrAssetViewController) { return 0; }
