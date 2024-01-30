#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ETooltipVerticalAlignment.h"
#include "Layout/Margin.h"
#include "CoreSelectableButtonWidget.h"
#include "EStoreItemLayout.h"
#include "ETooltipHorizontalAlignment.h"
#include "EFlagSize.h"
#include "CoreStoreItemWidget.generated.h"

class UWidget;
class UCorePriceTagWidget;
class UCoreTimerFlagWidget;
class UVerticalBox;
class UDBDImage;
class UScaleBox;
class UCoreOnHoverBorderWidget;
class UTextBlock;
class UStoreItemViewData;
class UCoreButtonWidget;

UCLASS(Abstract, EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _layoutMask;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	FMargin _priceTagPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	FMargin _timerFlagPadding;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCorePriceTagWidget> _priceTagWidgetClass;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreTimerFlagWidget> _timerFlagWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETooltipHorizontalAlignment _tooltipHorizontalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETooltipVerticalAlignment _tooltipVerticalAlignment;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDImage* ItemIcon;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UScaleBox* LayoutScale;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UWidget* SelectedOverlay;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreOnHoverBorderWidget* OnHoverBorder;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UVerticalBox* TimerFlagVerticalBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UVerticalBox* PriceTagsVerticalBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* OwnedTagText;

	UPROPERTY(BlueprintReadOnly, Transient, Export)
	TArray<UCoreTimerFlagWidget*> _timerFlagWidgets;

	UPROPERTY(BlueprintReadWrite, Transient)
	EFlagSize _flagSize;

public:
	UFUNCTION(BlueprintCallable)
	void SetTimerFlagSize(EFlagSize flagSize);

	UFUNCTION(BlueprintCallable)
	void SetStoreItemLayout(int32 layoutMask);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetStoreItemData(UStoreItemViewData* data);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetSmallTemplate(bool useSmallTemplate);

	UFUNCTION(BlueprintCallable)
	void SetScale(float scale);

protected:
	UFUNCTION()
	void OnButtonUnhovered(UCoreButtonWidget* targetButton);

	UFUNCTION()
	void OnButtonSelectedChanged(UCoreSelectableButtonWidget* targetButton, bool isSelected);

	UFUNCTION()
	void OnButtonHovered(UCoreButtonWidget* targetButton);

	UFUNCTION(BlueprintPure)
	bool IsTagVisible(EStoreItemLayout tag) const;

	UFUNCTION(BlueprintCallable)
	UCoreTimerFlagWidget* CreateTimerFlagWidget();

	UFUNCTION(BlueprintCallable)
	UCorePriceTagWidget* CreatePriceTagWidget();

	UFUNCTION(BlueprintCallable)
	void ClearTimerFlagWidgets();

	UFUNCTION(BlueprintCallable)
	void ClearPriceTagWidgets();

public:
	UCoreStoreItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreItemWidget) { return 0; }
