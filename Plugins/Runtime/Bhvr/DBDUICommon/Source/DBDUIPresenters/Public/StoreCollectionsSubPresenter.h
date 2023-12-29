#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "StoreCollectionsSubPresenter.generated.h"

class UStoreCollectionViewData;

UCLASS()
class DBDUIPRESENTERS_API UStoreCollectionsSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<UStoreCollectionViewData*> _specialCollectionsViewData;

	UPROPERTY(Transient)
	TArray<UStoreCollectionViewData*> _featuredCollectionsViewData;

	UPROPERTY(Transient)
	TArray<UStoreCollectionViewData*> _allCollectionsViewData;

public:
	UStoreCollectionsSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreCollectionsSubPresenter) { return 0; }
