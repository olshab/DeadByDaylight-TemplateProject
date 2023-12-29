#pragma once

#include "CoreMinimal.h"
#include "SpecialPackBuyActionDelegate.h"
#include "Templates/SubclassOf.h"
#include "CoreSelectableButtonWidget.h"
#include "CoreStoreChapterPackItemWidget.generated.h"

class UCoreStoreCustomizationItemWidget;
class UDBDTextBlock;
class UCorePreConstructableList;
class UHorizontalBox;
class UCorePremiumCurrencyButtonWidget;
class UCoreStoreCharacterItemWidget;
class UStoreChapterPackViewData;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreChapterPackItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSpecialPackBuyActionDelegate BuyPremiumActionDelegate;

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TitleText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UHorizontalBox* CharactersBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UHorizontalBox* CustomizationsBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCorePremiumCurrencyButtonWidget* PremiumBuyButton;

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
	UStoreChapterPackViewData* _data;

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
	void SetData(UStoreChapterPackViewData* data);

protected:
	UFUNCTION()
	void OnPremiumBuyButtonClicked(UCoreButtonWidget* button);

public:
	UCoreStoreChapterPackItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreChapterPackItemWidget) { return 0; }
