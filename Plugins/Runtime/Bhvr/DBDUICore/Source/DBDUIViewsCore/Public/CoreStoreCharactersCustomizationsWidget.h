#pragma once

#include "CoreMinimal.h"
#include "CoreBaseUserWidget.h"
#include "StoreCharactersCustomizationsViewInterface.h"
#include "StoreCustomizationSelectedDelegate.h"
#include "Templates/SubclassOf.h"
#include "StoreCategorySelectedDelegate.h"
#include "CoreStoreCharactersCustomizationsWidget.generated.h"

class UUniformGridPanel;
class UCoreStoreCustomizationItemWidget;
class UScrollBox;
class UCoreStoreCategoryWidget;
class UCoreStoreCharactersFilterWidget;
class UCorePreConstructableList;
class UCoreSelectableButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreCharactersCustomizationsWidget : public UCoreBaseUserWidget, public IStoreCharactersCustomizationsViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FStoreCustomizationSelectedDelegate _customizationSelectedDelegate;

	UPROPERTY()
	FStoreCategorySelectedDelegate _categorySelectedDelegate;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreCustomizationItemWidget> _customizationItemWidgetClass;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreCategoryWidget> _categoryItemWidgetClass;

	UPROPERTY(EditAnywhere)
	int32 _numberOfColumns;

	UPROPERTY(EditAnywhere)
	float _customizationItemScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _layoutMask;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UScrollBox* CustomizationsScroll;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UUniformGridPanel* CustomizationsContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UUniformGridPanel* CategoriesContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreStoreCharactersFilterWidget* FiltersWidget;

	UPROPERTY(Transient, Export)
	TArray<UCoreStoreCustomizationItemWidget*> _selectedCustomizationItems;

	UPROPERTY(Transient)
	int32 _maxSelectedItems;

	UPROPERTY(Transient, meta=(BindWidget))
	UCoreStoreCategoryWidget* _selectedCategoryItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedCategoriesCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedCustomizationsCount;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _categoryList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _customizationList;

protected:
	UFUNCTION()
	void OnCustomizationSelectedAgain(UCoreSelectableButtonWidget* buttonTarget);

	UFUNCTION()
	void OnCustomizationSelected(UCoreSelectableButtonWidget* buttonTarget, bool isSelected);

	UFUNCTION()
	void OnCategorySelected(UCoreSelectableButtonWidget* buttonTarget, bool isSelected);

public:
	UCoreStoreCharactersCustomizationsWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCharactersCustomizationsWidget) { return 0; }
