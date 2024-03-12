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
class UCorePreConstructableList;
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 _preConstructedPriceTagCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 _preConstructedTimerFlagCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETooltipHorizontalAlignment _tooltipHorizontalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETooltipVerticalAlignment _tooltipVerticalAlignment;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDImage* ItemIMG;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UScaleBox* LayoutScale;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UWidget* SelectedOverlay;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreOnHoverBorderWidget* OnHoverBorder;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UVerticalBox* TimerFlagVerticalBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UVerticalBox* PriceTagsVerticalBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UTextBlock* UnavailableTagTB;

	UPROPERTY(Transient)
	UCorePreConstructableList* _priceTagsList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _timerFlagsList;

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

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetNotificationTag(const bool isNew);

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
