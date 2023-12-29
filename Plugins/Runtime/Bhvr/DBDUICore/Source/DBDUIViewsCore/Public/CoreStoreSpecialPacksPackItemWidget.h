#pragma once

#include "CoreMinimal.h"
#include "SpecialPackBuyActionDelegate.h"
#include "Templates/SubclassOf.h"
#include "CoreSelectableButtonWidget.h"
#include "CoreStoreSpecialPacksPackItemWidget.generated.h"

class UCoreStoreCustomizationItemWidget;
class UDBDTextBlock;
class UCorePreConstructableList;
class UHorizontalBox;
class UCoreCurrencySwitcherWidget;
class UCoreStoreCharacterItemWidget;
class UStoreSpecialPackViewData;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreSpecialPacksPackItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSpecialPackBuyActionDelegate BuyWithCurrencyActionDelegate;

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TimerText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TitleText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UHorizontalBox* CharactersBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UHorizontalBox* CustomizationsBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreCurrencySwitcherWidget* CurrencyBuyButton;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool _isExpanded;

	UPROPERTY(EditAnywhere)
	int32 _initialItemPoolSize;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreCharacterItemWidget> _characterItemWidgetClass;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreCustomizationItemWidget> _customizationItemWidgetClass;

private:
	UPROPERTY(Transient)
	UStoreSpecialPackViewData* _data;

	UPROPERTY(Transient)
	UCorePreConstructableList* _characterList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _customizationList;

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ToggleExpanded();

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetExpanded(bool expanded);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(UStoreSpecialPackViewData* data);

protected:
	UFUNCTION()
	void OnCurrencyBuyButtonClicked();

public:
	UCoreStoreSpecialPacksPackItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreSpecialPacksPackItemWidget) { return 0; }
