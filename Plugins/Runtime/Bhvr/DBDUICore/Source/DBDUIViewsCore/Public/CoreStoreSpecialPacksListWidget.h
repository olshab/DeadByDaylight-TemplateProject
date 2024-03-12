#pragma once

#include "CoreMinimal.h"
#include "StoreSpecialPacksListViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreSpecialPacksListWidget.generated.h"

class UCoreStoreSpecialPackItemWidget;
class UDBDScrollBox;
class UUniformGridPanel;
class UCorePreConstructableList;

UCLASS(EditInlineNew)
class UCoreStoreSpecialPacksListWidget : public UCoreBaseUserWidget, public IStoreSpecialPacksListViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	int32 _preConstructedItemsCount;

	UPROPERTY(EditDefaultsOnly)
	int32 _numOfColumns;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	TSubclassOf<UCoreStoreSpecialPackItemWidget> _itemWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUniformGridPanel* ContentGrid;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDScrollBox* Scroll;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _itemList;

private:
	UFUNCTION()
	void OnItemClicked(const FString& packId);

public:
	UCoreStoreSpecialPacksListWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreSpecialPacksListWidget) { return 0; }
