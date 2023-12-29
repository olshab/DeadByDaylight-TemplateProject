#pragma once

#include "CoreMinimal.h"
#include "CoreBaseUserWidget.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreCollectionsItemWidget.generated.h"

class UStoreCollectionViewData;
class UCoreStoreCustomizationItemWidget;
class UDBDTextBlock;
class UHorizontalBox;
class UCorePreConstructableList;

UCLASS(EditInlineNew)
class UCoreStoreCollectionsItemWidget : public UCoreBaseUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TimerText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* CountText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UHorizontalBox* StoreCustomizationListBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	TSubclassOf<UCoreStoreCustomizationItemWidget> _storeCustomizationItemWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedItemsCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _layoutMask;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _itemList;

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ToggleExpanded();

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetupView(UStoreCollectionViewData* collectionViewData);

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetExpanded(bool expanded);

public:
	UCoreStoreCollectionsItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCollectionsItemWidget) { return 0; }
