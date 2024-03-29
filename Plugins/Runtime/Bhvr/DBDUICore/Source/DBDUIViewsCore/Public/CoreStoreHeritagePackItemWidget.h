#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "StoreHeritagePackViewData.h"
#include "CoreStoreHeritagePackItemWidget.generated.h"

class UCoreOnHoverBorderWidget;
class UDBDTextBlock;
class UCorePremiumCurrencyButtonWidget;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreHeritagePackItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* ContentDescriptionTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCorePremiumCurrencyButtonWidget* PremiumBuyButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreOnHoverBorderWidget* OnHoverBorder;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(const FStoreHeritagePackViewData& data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnItemUnhovered(UCoreButtonWidget* button);

protected:
	UFUNCTION()
	void OnBuyButtonClicked(UCoreButtonWidget* button);

public:
	UCoreStoreHeritagePackItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreHeritagePackItemWidget) { return 0; }
