#pragma once

#include "CoreMinimal.h"
#include "ECurrencyType.h"
#include "StoreItemEquipClickedDelegate.h"
#include "Layout/Margin.h"
#include "StoreCharactersViewInterface.h"
#include "CoreStoreBaseSubTabsWidget.h"
#include "StoreItemEquipAllClickedDelegate.h"
#include "StoreItemUnlockClickedDelegate.h"
#include "StoreItemAlternativeUnlockClickedDelegate.h"
#include "StoreItemSelectAllClickedDelegate.h"
#include "StoreItemPlayMoriClickedDelegate.h"
#include "Framework/Text/TextLayout.h"
#include "StoreItemZoomCharmClickedDelegate.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreCharactersWidget.generated.h"

class UCoreCurrencyInputSwitcherWidget;
class UDBDTextBlock;
class UCoreButtonWidget;
class UVerticalBox;
class UCorePreConstructableList;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreCharactersWidget : public UCoreStoreBaseSubTabsWidget, public IStoreCharactersViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FStoreItemUnlockClickedDelegate _characterUnlockClickedDelegate;

	UPROPERTY()
	FStoreItemUnlockClickedDelegate _customizationUnlockClickedDelegate;

	UPROPERTY()
	FStoreItemEquipClickedDelegate _characterEquipClickedDelegate;

	UPROPERTY()
	FStoreItemEquipClickedDelegate _customizationEquipClickedDelegate;

	UPROPERTY()
	FStoreItemEquipAllClickedDelegate _customizationEquipAllClickedDelegate;

	UPROPERTY()
	FStoreItemSelectAllClickedDelegate _customizationSelectAllClickedDelegate;

	UPROPERTY()
	FStoreItemAlternativeUnlockClickedDelegate _characterAlternativeUnlockClickedDelegate;

	UPROPERTY()
	FStoreItemAlternativeUnlockClickedDelegate _customizationAlternativeUnlockClickedDelegate;

	UPROPERTY()
	FStoreItemPlayMoriClickedDelegate _playMoriClickedDelegate;

	UPROPERTY()
	FStoreItemZoomCharmClickedDelegate _zoomCharmClickedDelegate;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreCurrencyInputSwitcherWidget> _currencySwitcherWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 _preConstructedCurrencyButtonCount;

	UPROPERTY(EditAnywhere, NoClear)
	FMargin _currencyButtonPadding;

	UPROPERTY(EditAnywhere, NoClear)
	TEnumAsByte<ETextJustify::Type> _currencyButtonAlignment;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* SelectedCharacterNameTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* CurrencyButtonsTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UVerticalBox* CurrencyButtonsVerticalBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* EquipButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* EquipAllButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* SelectAllButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* AlternativeUnlockButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* AlternativeUnlockMessageTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* AlternativeUnlockNameTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* PlayMoriButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* ZoomCharmButton;

	UPROPERTY(Transient)
	UCorePreConstructableList* _currencyButtonList;

protected:
	UFUNCTION()
	void OnZoomCharmClicked(UCoreButtonWidget* buttonTarget);

	UFUNCTION()
	void OnPlayMoriClicked(UCoreButtonWidget* buttonTarget);

	UFUNCTION()
	void OnItemUnlockTriggered(const ECurrencyType currencyType);

	UFUNCTION()
	void OnItemSelectAllClicked(UCoreButtonWidget* buttonTarget);

	UFUNCTION()
	void OnItemEquipClicked(UCoreButtonWidget* buttonTarget);

	UFUNCTION()
	void OnItemEquipAllClicked(UCoreButtonWidget* buttonTarget);

	UFUNCTION()
	void OnItemAlternativeUnlockClicked(UCoreButtonWidget* buttonTarget);

public:
	UCoreStoreCharactersWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCharactersWidget) { return 0; }
