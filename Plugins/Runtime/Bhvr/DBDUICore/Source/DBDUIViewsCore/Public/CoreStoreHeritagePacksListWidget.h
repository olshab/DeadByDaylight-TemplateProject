#pragma once

#include "CoreMinimal.h"
#include "StoreHeritagePacksListViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreHeritagePacksListWidget.generated.h"

class UCoreStoreHeritagePackItemWidget;
class UScrollBox;
class UUniformGridPanel;
class UCorePreConstructableList;

UCLASS(EditInlineNew)
class UCoreStoreHeritagePacksListWidget : public UCoreBaseUserWidget, public IStoreHeritagePacksListViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	int32 _preConstructedItemsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	TSubclassOf<UCoreStoreHeritagePackItemWidget> _itemWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUniformGridPanel* Content;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UScrollBox* Scroll;

	UPROPERTY(EditDefaultsOnly)
	int32 _numOfColumns;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _itemList;

private:
	UFUNCTION()
	void OnPackSeen(const FString& packId);

	UFUNCTION()
	void OnPackBuyButtonClicked(const FString& packId);

public:
	UCoreStoreHeritagePacksListWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreHeritagePacksListWidget) { return 0; }
