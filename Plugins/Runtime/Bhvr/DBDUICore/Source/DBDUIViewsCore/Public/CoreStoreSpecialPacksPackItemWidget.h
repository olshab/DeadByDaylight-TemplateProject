#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "SpecialPackCustomizationClickedDelegate.h"
#include "Templates/SubclassOf.h"
#include "SpecialPackCharacterClickedDelegate.h"
#include "SpecialPackBuyActionDelegate.h"
#include "ArchivePassClickDelegate.h"
#include "CoreStoreSpecialPacksPackItemWidget.generated.h"

class UCoreStoreCustomizationItemWidget;
class UDBDTextBlock;
class UCorePreConstructableList;
class UHorizontalBox;
class UCoreCurrencySwitcherWidget;
class UCoreStoreArchivePassItemWidget;
class UCoreStoreCharacterItemWidget;
class UStoreSpecialPackViewData;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreSpecialPacksPackItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSpecialPackBuyActionDelegate BuyWithCurrencyActionDelegate;

	UPROPERTY()
	FSpecialPackCharacterClickedDelegate CharacterClickedDelegate;

	UPROPERTY()
	FSpecialPackCustomizationClickedDelegate CustomizationClickedDelegate;

	UPROPERTY()
	FArchivePassClickDelegate ArchivePassClickDelegate;

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TimerText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TitleText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UHorizontalBox* ArchivePassBox;

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

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreArchivePassItemWidget> _archivePassItemWidgetClass;

private:
	UPROPERTY(Transient)
	UStoreSpecialPackViewData* _data;

	UPROPERTY(Transient)
	UCorePreConstructableList* _characterList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _customizationList;

	UPROPERTY(Transient, Export)
	UCoreStoreArchivePassItemWidget* _archivePassItem;

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
	void OnCustomizationItemClicked(UCoreButtonWidget* button);

	UFUNCTION()
	void OnCurrencyBuyButtonClicked();

	UFUNCTION()
	void OnCharacterItemClicked(UCoreButtonWidget* button);

	UFUNCTION()
	void OnArchivePassItemClicked(UCoreButtonWidget* button);

public:
	UCoreStoreSpecialPacksPackItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreSpecialPacksPackItemWidget) { return 0; }
