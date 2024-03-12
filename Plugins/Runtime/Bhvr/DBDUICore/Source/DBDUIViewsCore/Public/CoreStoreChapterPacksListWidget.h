#pragma once

#include "CoreMinimal.h"
#include "StoreChapterPacksListViewInterface.h"
#include "StoreRedirectionData.h"
#include "CoreBaseUserWidget.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreChapterPacksListWidget.generated.h"

class UCoreStoreChapterPackItemWidget;
class UVerticalBox;
class UScrollBox;
class UCorePreConstructableList;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreChapterPacksListWidget : public UCoreBaseUserWidget, public IStoreChapterPacksListViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	int32 _preConstructedItemsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	TSubclassOf<UCoreStoreChapterPackItemWidget> _itemWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UVerticalBox* Content;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UScrollBox* Scroll;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _itemList;

private:
	UFUNCTION()
	void OnItemSeen(const FString& packId);

	UFUNCTION()
	void OnItemCustomizationClicked(const FStoreRedirectionData& redirectionData);

	UFUNCTION()
	void OnItemCharacterClicked(const FStoreRedirectionData& redirectionData);

	UFUNCTION()
	void OnItemBuyActionClicked(const FString& packId);

public:
	UCoreStoreChapterPacksListWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreChapterPacksListWidget) { return 0; }
