#pragma once

#include "CoreMinimal.h"
#include "StoreCharmSlotSelectedDelegate.h"
#include "CoreBaseUserWidget.h"
#include "StoreCharactersCustomizationsViewInterface.h"
#include "StoreCustomizationSelectedDelegate.h"
#include "Templates/SubclassOf.h"
#include "StorePresetSelectedDelegate.h"
#include "StoreCategorySelectedDelegate.h"
#include "Layout/Margin.h"
#include "CoreStoreCharactersCustomizationsWidget.generated.h"

class UCoreSelectableButtonWidget;
class UUniformGridPanel;
class UCoreStoreCustomizationItemWidget;
class UDBDScrollBox;
class UCoreStoreCategoryWidget;
class UCoreStorePresetWidget;
class UCoreStoreCharmSlotWidget;
class UHorizontalBox;
class UCoreStoreEmptyItemWidget;
class UCoreStoreCharactersFilterWidget;
class UCoreSearchBarWidget;
class UCorePreConstructableList;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreCharactersCustomizationsWidget : public UCoreBaseUserWidget, public IStoreCharactersCustomizationsViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FStoreCustomizationSelectedDelegate _customizationSelectedDelegate;

	UPROPERTY()
	FStoreCategorySelectedDelegate _categorySelectedDelegate;

	UPROPERTY()
	FStoreCharmSlotSelectedDelegate _charmSlotSelectedDelegate;

	UPROPERTY()
	FStorePresetSelectedDelegate _presetSelectedDelegate;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreCustomizationItemWidget> _customizationItemWidgetClass;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreCategoryWidget> _categoryItemWidgetClass;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreCharmSlotWidget> _charmSlotItemWidgetClass;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStorePresetWidget> _presetItemWidgetClass;

	UPROPERTY(EditAnywhere)
	int32 _numberOfColumns;

	UPROPERTY(EditAnywhere)
	float _customizationItemScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _layoutMask;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDScrollBox* CustomizationsScroll;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUniformGridPanel* CustomizationsContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUniformGridPanel* CategoriesContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UHorizontalBox* CharmSlotsContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UHorizontalBox* PresetsContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreEmptyItemWidget* EmptyItem;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreCharactersFilterWidget* FiltersWidget;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreSearchBarWidget* SearchBar;

	UPROPERTY(Transient, Export)
	TArray<UCoreStoreCustomizationItemWidget*> _allCustomizationItems;

	UPROPERTY(Transient, meta=(BindWidgetOptional))
	UCoreStoreCustomizationItemWidget* _selectedCustomizationItem;

	UPROPERTY(Transient, meta=(BindWidgetOptional))
	UCoreStoreCategoryWidget* _selectedCategoryItem;

	UPROPERTY(Transient, meta=(BindWidgetOptional))
	UCoreStoreCharmSlotWidget* _selectedCharmSlotItem;

	UPROPERTY(Transient, meta=(BindWidgetOptional))
	UCoreStorePresetWidget* _selectedPresetItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedCategoriesCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedCustomizationsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedCharmSlotsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedPresetsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	FMargin _charmSlotsPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	FMargin _presetsPadding;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _categoryList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _customizationList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _charmSlotList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _presetList;

protected:
	UFUNCTION()
	void OnPresetSelected(UCoreSelectableButtonWidget* buttonTarget, bool isSelected);

	UFUNCTION()
	void OnEmptyItemSelectedAgain(UCoreSelectableButtonWidget* buttonTarget);

	UFUNCTION()
	void OnEmptyItemSelected(UCoreSelectableButtonWidget* buttonTarget, bool isSelected);

	UFUNCTION()
	void OnCustomizationSelectedAgain(UCoreSelectableButtonWidget* buttonTarget);

	UFUNCTION()
	void OnCustomizationSelected(UCoreSelectableButtonWidget* buttonTarget, bool isSelected);

	UFUNCTION()
	void OnCharmSlotSelected(UCoreSelectableButtonWidget* buttonTarget, bool isSelected);

	UFUNCTION()
	void OnCategorySelected(UCoreSelectableButtonWidget* buttonTarget, bool isSelected);

public:
	UCoreStoreCharactersCustomizationsWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCharactersCustomizationsWidget) { return 0; }
