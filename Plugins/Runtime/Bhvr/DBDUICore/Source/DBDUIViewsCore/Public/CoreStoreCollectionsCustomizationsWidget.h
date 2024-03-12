#pragma once

#include "CoreMinimal.h"
#include "ECurrencyType.h"
#include "StoreCollectionsCustomizationsViewInterface.h"
#include "StoreCollectionItemUnlockClickedDelegate.h"
#include "Framework/Text/TextLayout.h"
#include "CoreBaseUserWidget.h"
#include "Templates/SubclassOf.h"
#include "StoreCollectionItemEquipedDelegate.h"
#include "Layout/Margin.h"
#include "CoreStoreCollectionsCustomizationsWidget.generated.h"

class UCoreCurrencyInputSwitcherWidget;
class UDBDTextBlock;
class UCorePreConstructableList;
class UHorizontalBox;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreCollectionsCustomizationsWidget : public UCoreBaseUserWidget, public IStoreCollectionsCustomizationsViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FStoreCollectionItemUnlockClickedDelegate _onCollectionItemUnlockClicked;

	UPROPERTY()
	FStoreCollectionItemEquipedDelegate _onCollectionItemEquipClicked;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreCurrencyInputSwitcherWidget> _currencySwitcherWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 _preConstructedCurrencyButtonCount;

	UPROPERTY(EditAnywhere, NoClear)
	FMargin _currencyButtonPadding;

	UPROPERTY(EditAnywhere, NoClear)
	TEnumAsByte<ETextJustify::Type> _currencyButtonAlignment;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* CurrencyButtonsTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UHorizontalBox* CurrencyButtonsHorizontalBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* EquipButton;

	UPROPERTY(Transient)
	UCorePreConstructableList* _currencyButtonList;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* CollectionNameTB;

private:
	UFUNCTION()
	void OnItemUnlockTriggered(const ECurrencyType currencyType);

	UFUNCTION()
	void OnItemEquipClicked(UCoreButtonWidget* buttonTarget);

public:
	UCoreStoreCollectionsCustomizationsWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCollectionsCustomizationsWidget) { return 0; }
