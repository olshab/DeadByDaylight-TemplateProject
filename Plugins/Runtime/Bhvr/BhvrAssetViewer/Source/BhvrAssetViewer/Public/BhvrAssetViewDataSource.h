#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AssetViewDataSourceLoadingStateChanged.h"
#include "BhvrAssetViewOption.h"
#include "AssetViewDataSourceSelectionStateChanged.h"
#include "BhvrAssetViewDataSource.generated.h"

class UBhvrAssetViewData;

UCLASS(BlueprintType, Abstract, Transient)
class BHVRASSETVIEWER_API UBhvrAssetViewDataSource : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FAssetViewDataSourceLoadingStateChanged LoadingStateChanged;

	UPROPERTY(BlueprintAssignable)
	FAssetViewDataSourceSelectionStateChanged AssetViewDataSelectionStateChanged;

private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	FString Id;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	TArray<FBhvrAssetViewOption> AssetViewDataOptions;

	UPROPERTY(Transient)
	TMap<FString, UBhvrAssetViewData*> AssetViewDatas;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	bool bIsLoading;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	UBhvrAssetViewData* SelectedAssetViewData;

public:
	UFUNCTION(BlueprintCallable)
	void SelectAssetViewData(const FString& AssetViewDataId);

	UFUNCTION(BlueprintPure)
	bool IsLoading() const;

	UFUNCTION(BlueprintPure)
	UBhvrAssetViewData* GetSelectedAssetViewData();

	UFUNCTION(BlueprintPure)
	FString GetId() const;

	UFUNCTION(BlueprintPure)
	FString GetDisplayName() const;

public:
	UBhvrAssetViewDataSource();
};

FORCEINLINE uint32 GetTypeHash(const UBhvrAssetViewDataSource) { return 0; }
