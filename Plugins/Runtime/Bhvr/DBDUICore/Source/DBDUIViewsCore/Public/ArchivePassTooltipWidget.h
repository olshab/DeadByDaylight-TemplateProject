#pragma once

#include "CoreMinimal.h"
#include "TooltipWidget.h"
#include "ArchivePassTooltipViewData.h"
#include "ArchivePassTooltipWidget.generated.h"

class UDBDTextBlock;
class UCorePriceTagWidget;
class UDBDRichTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UArchivePassTooltipWidget : public UTooltipWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* SubTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDRichTextBlock* DescriptionRTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCorePriceTagWidget* PriceTag;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetTooltipData(const FArchivePassTooltipViewData& data);

public:
	UArchivePassTooltipWidget();
};

FORCEINLINE uint32 GetTypeHash(const UArchivePassTooltipWidget) { return 0; }
