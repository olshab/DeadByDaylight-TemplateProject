#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "StoreCollectionsSubPresenter.generated.h"

class UStoreCollectionsListSubPresenter;
class USubPresenter;
class UStoreCollectionsCustomizationsSubPresenter;
class UStoreCollectionViewData;

UCLASS()
class DBDUIPRESENTERS_API UStoreCollectionsSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UStoreCollectionsListSubPresenter* _collectionsListSubPresenter;

	UPROPERTY(Transient)
	UStoreCollectionsCustomizationsSubPresenter* _collectionsCustomizationsSubPresenter;

	UPROPERTY(Transient)
	UStoreSubPresenter* _activeSubPresenter;

	UPROPERTY(Transient)
	UStoreSubPresenter* _previousActiveSubPresenter;

private:
	UFUNCTION()
	void OnStopSubPresenterAsyncOperation(USubPresenter* subPresenter);

	UFUNCTION()
	void OnStartSubPresenterAsyncOperation(USubPresenter* subPresenter);

	UFUNCTION()
	void OnCollectionClicked(const UStoreCollectionViewData* collection);

	UFUNCTION()
	void OnBackActionLabelChangeRequested(const FText& text);

	UFUNCTION()
	void HandleSubPresenterError();

public:
	UStoreCollectionsSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreCollectionsSubPresenter) { return 0; }
