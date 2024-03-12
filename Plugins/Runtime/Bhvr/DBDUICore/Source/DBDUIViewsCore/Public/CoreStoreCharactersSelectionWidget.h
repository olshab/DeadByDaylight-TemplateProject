#pragma once

#include "CoreMinimal.h"
#include "CoreBaseUserWidget.h"
#include "StoreCharactersSelectionViewInterface.h"
#include "StoreCharacterSelectedDelegate.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreCharactersSelectionWidget.generated.h"

class UCoreStoreCharacterItemWidget;
class UCoreSearchBarWidget;
class UDBDScrollBox;
class UCoreStoreCharactersFilterWidget;
class UUniformGridPanel;
class UCoreButtonWidget;
class UCoreStoreCharacterPerksToastWidget;
class UCoreSelectableButtonWidget;
class UCorePreConstructableList;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreCharactersSelectionWidget : public UCoreBaseUserWidget, public IStoreCharactersSelectionViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FStoreCharacterSelectedDelegate _characterSelectedDelegate;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreCharacterItemWidget> _itemWidgetClass;

	UPROPERTY(EditAnywhere)
	int32 _numberOfColumns;

	UPROPERTY(EditAnywhere)
	float _itemScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _layoutMask;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedItemsCount;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDScrollBox* ScrollBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUniformGridPanel* Container;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreCharactersFilterWidget* FiltersWidget;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreSearchBarWidget* SearchBar;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* PerksToastButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreCharacterPerksToastWidget* PerksToast;

	UPROPERTY(Transient, Export)
	TArray<UCoreStoreCharacterItemWidget*> _allCharacterItems;

	UPROPERTY(Transient, meta=(BindWidgetOptional))
	UCoreStoreCharacterItemWidget* _selectedItem;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _characterList;

protected:
	UFUNCTION()
	void OnPerkToastButtonClick(UCoreButtonWidget* buttonTarget);

	UFUNCTION()
	void OnCharacterSelected(UCoreSelectableButtonWidget* buttonTarget, bool isSelected);

public:
	UCoreStoreCharactersSelectionWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCharactersSelectionWidget) { return 0; }
