#pragma once

#include "CoreMinimal.h"
#include "AssetViewerViewControllerSelectionStateChanged.h"
#include "GameFramework/Actor.h"
#include "AssetViewerLoadingStateChanged.h"
#include "Templates/SubclassOf.h"
#include "AssetViewerViewDataSourceSelectionStateChanged.h"
#include "BhvrAssetViewOption.h"
#include "BhvrAssetViewer.generated.h"

class UBhvrAssetViewDataSource;
class UBhvrAssetViewController;
class UBhvrAssetViewData;
class ATargetPoint;

UCLASS()
class BHVRASSETVIEWER_API ABhvrAssetViewer : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FAssetViewerLoadingStateChanged LoadingStateChanged;

	UPROPERTY(BlueprintAssignable)
	FAssetViewerViewDataSourceSelectionStateChanged AssetViewDataSourceSelectionStateChanged;

	UPROPERTY(BlueprintAssignable)
	FAssetViewerViewControllerSelectionStateChanged AssetViewControllerSelectionStateChanged;

private:
	UPROPERTY(BlueprintReadOnly, NoClear, meta=(AllowPrivateAccess=true))
	TSubclassOf<UBhvrAssetViewDataSource> AssetViewDataSourceBaseClass;

	UPROPERTY(BlueprintReadOnly, NoClear, meta=(AllowPrivateAccess=true))
	TSubclassOf<UBhvrAssetViewController> AssetViewControllerBaseClass;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(AllowPrivateAccess=true))
	ATargetPoint* AssetSpawnPoint;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(AllowPrivateAccess=true))
	TArray<FBhvrAssetViewOption> AssetViewDataSourceOptions;

	UPROPERTY(Transient)
	TMap<FString, UBhvrAssetViewDataSource*> AssetViewDataSources;

	UPROPERTY(Transient)
	TArray<UBhvrAssetViewController*> AssetViewControllers;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	bool bIsLoading;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	UBhvrAssetViewDataSource* SelectedAssetViewDataSource;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	UBhvrAssetViewController* SelectedAssetViewController;

public:
	UFUNCTION(BlueprintCallable)
	void SelectAssetViewDataSource(const FString& AssetViewDataSourceId);

private:
	UFUNCTION()
	void OnSelectedAssetViewDataChanged(UBhvrAssetViewData* OldAssetViewData, UBhvrAssetViewData* NewAssetViewData);

public:
	UFUNCTION(BlueprintPure)
	bool IsLoading() const;

	UFUNCTION(BlueprintPure)
	UBhvrAssetViewDataSource* GetSelectedAssetViewDataSource() const;

	UFUNCTION(BlueprintPure)
	UBhvrAssetViewController* GetSelectedAssetViewController() const;

	UFUNCTION(BlueprintCallable)
	void BeginPlay();

public:
	ABhvrAssetViewer();
};

FORCEINLINE uint32 GetTypeHash(const ABhvrAssetViewer) { return 0; }
