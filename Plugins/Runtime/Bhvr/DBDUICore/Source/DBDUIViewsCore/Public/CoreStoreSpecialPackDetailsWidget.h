#pragma once

#include "CoreMinimal.h"
#include "StoreSpecialPacksDetailsViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreSpecialPackDetailsWidget.generated.h"

class UCoreStoreArchivePassItemWidget;
class UCoreStoreCharacterItemWidget;
class UCoreCurrencyButtonWidget;
class UDBDRichTextBlock;
class UDBDImage;
class UPanelWidget;
class UDBDTextBlock;
class UCorePremiumCurrencyButtonWidget;
class UCoreStoreArchiveFragmentItemWidget;
class UCoreStoreCustomizationItemWidget;
class UStoreSpecialPackViewData;
class UCorePreConstructableList;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreSpecialPackDetailsWidget : public UCoreBaseUserWidget, public IStoreSpecialPacksDetailsViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDImage* PackIMG;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* PackTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* OwnedTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDRichTextBlock* SubTextRTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UPanelWidget* ContentPanel;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreCurrencyButtonWidget* CurrencyBuyButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCorePremiumCurrencyButtonWidget* PremiumBuyButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreArchivePassItemWidget* ArchivePassItem;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreArchiveFragmentItemWidget* ArchiveFragmentItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	TSubclassOf<UCoreStoreCharacterItemWidget> _characterItemWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 _characterPoolSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	TSubclassOf<UCoreStoreCustomizationItemWidget> _customizationItemWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 _customizationPoolSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 _numOfColumns;

	UPROPERTY(Transient)
	UStoreSpecialPackViewData* _data;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _characterList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _customizationList;

protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnShowAnimationFinished();

private:
	UFUNCTION()
	void OnPremiumButtonClicked(UCoreButtonWidget* button);

protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnHideAnimationFinished();

private:
	UFUNCTION()
	void OnCustomizationClicked(UCoreButtonWidget* button);

	UFUNCTION()
	void OnCurrencyButtonClicked(UCoreButtonWidget* button);

	UFUNCTION()
	void OnCharacterClicked(UCoreButtonWidget* button);

	UFUNCTION()
	void OnArchivePassClicked(UCoreButtonWidget* button);

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void AnimateShow();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void AnimateHide();

public:
	UCoreStoreSpecialPackDetailsWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreSpecialPackDetailsWidget) { return 0; }
