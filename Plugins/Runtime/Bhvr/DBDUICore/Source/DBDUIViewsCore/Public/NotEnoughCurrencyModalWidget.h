#pragma once

#include "CoreMinimal.h"
#include "ModalWidget.h"
#include "NotEnoughCurrencyModalViewData.h"
#include "NotEnoughCurrencyModalWidget.generated.h"

class UDBDRichTextBlock;
class UCoreKeyListenerButtonWidget;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UNotEnoughCurrencyModalWidget : public UModalWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDRichTextBlock* ContentRTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreKeyListenerButtonWidget* Button;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetTooltipData(const FNotEnoughCurrencyModalViewData& data);

private:
	UFUNCTION()
	void OnUnhovered(UCoreButtonWidget* unhoveredButton);

	UFUNCTION()
	void OnHovered(UCoreButtonWidget* hoveredButton);

	UFUNCTION()
	void OnButtonClicked(UCoreButtonWidget* clickedButton);

public:
	UNotEnoughCurrencyModalWidget();
};

FORCEINLINE uint32 GetTypeHash(const UNotEnoughCurrencyModalWidget) { return 0; }
