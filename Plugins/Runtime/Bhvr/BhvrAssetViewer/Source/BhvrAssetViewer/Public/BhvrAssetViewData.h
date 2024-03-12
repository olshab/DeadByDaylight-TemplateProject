#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AssetViewDataLoadingStateChanged.h"
#include "BhvrAssetViewData.generated.h"

UCLASS(BlueprintType, Abstract, Transient)
class BHVRASSETVIEWER_API UBhvrAssetViewData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FAssetViewDataLoadingStateChanged LoadingStateChanged;

private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	FString Id;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	bool bIsLoading;

public:
	UFUNCTION(BlueprintPure)
	bool IsLoading() const;

	UFUNCTION(BlueprintPure)
	FString GetId() const;

	UFUNCTION(BlueprintPure)
	FString GetDisplayName() const;

public:
	UBhvrAssetViewData();
};

FORCEINLINE uint32 GetTypeHash(const UBhvrAssetViewData) { return 0; }
