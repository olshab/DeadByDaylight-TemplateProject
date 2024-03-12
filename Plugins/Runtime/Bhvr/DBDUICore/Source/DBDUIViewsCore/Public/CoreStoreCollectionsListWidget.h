#pragma once

#include "CoreMinimal.h"
#include "StoreCollectionsListViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreCollectionsListWidget.generated.h"

class UCoreStoreCollectionsItemWidget;
class UPanelWidget;
class UUniformGridPanel;
class UDBDTextBlock;
class UDBDScrollBox;
class UCoreSearchBarWidget;
class UCorePreConstructableList;
class UStoreCollectionViewData;

UCLASS(EditInlineNew)
class UCoreStoreCollectionsListWidget : public UCoreBaseUserWidget, public IStoreCollectionsListViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* CollectionsNotFoundTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreSearchBarWidget* SearchBar;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDScrollBox* ScrollBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUniformGridPanel* FeaturedUniformGrid;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUniformGridPanel* AllUniformGrid;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UPanelWidget* FeaturedContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	TSubclassOf<UCoreStoreCollectionsItemWidget> _collectionItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _featuredItemsColumnCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _allItemsColumnCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedFeaturedItemsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedAllItemsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float _featuredListHiddenThreshold;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _featuredItemsList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _allItemsList;

private:
	UFUNCTION()
	void UpdateTitleFromScroll(float currentOffset);

	UFUNCTION()
	void OnCollectionItemClicked(const UStoreCollectionViewData* collectionViewData);

public:
	UCoreStoreCollectionsListWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCollectionsListWidget) { return 0; }
