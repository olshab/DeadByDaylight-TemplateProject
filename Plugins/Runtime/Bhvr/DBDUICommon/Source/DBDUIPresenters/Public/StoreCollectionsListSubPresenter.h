#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "StoreCollectionsListSubPresenter.generated.h"

class UStoreCollectionViewData;

UCLASS()
class DBDUIPRESENTERS_API UStoreCollectionsListSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<UStoreCollectionViewData*> _combinedListsCollectionsViewData;

	UPROPERTY(Transient)
	TArray<UStoreCollectionViewData*> _featuredCollectionsViewData;

	UPROPERTY(Transient)
	TArray<UStoreCollectionViewData*> _allCollectionsViewData;

private:
	UFUNCTION()
	void UpdateCollectionsBySearch(const FString& searchString);

	UFUNCTION()
	void OnCollectionClicked(const UStoreCollectionViewData* collection);

public:
	UStoreCollectionsListSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreCollectionsListSubPresenter) { return 0; }
