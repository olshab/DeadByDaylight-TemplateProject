#pragma once

#include "CoreMinimal.h"
#include "TooltipWidget.h"
#include "ELockedElementType.h"
#include "Layout/Margin.h"
#include "LockedFeatureTooltipViewData.h"
#include "LockedFeatureTooltipWidget.generated.h"

class UDBDTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API ULockedFeatureTooltipWidget : public UTooltipWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	TMap<ELockedElementType, FMargin> _tooltipMargins;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* ContentTB;

	UPROPERTY(meta=(BindWidget))
	UDBDTextBlock* ProgressTB;

public:
	UFUNCTION(BlueprintNativeEvent)
	void SetTooltipData(const FLockedFeatureTooltipViewData& viewData);

public:
	ULockedFeatureTooltipWidget();
};

FORCEINLINE uint32 GetTypeHash(const ULockedFeatureTooltipWidget) { return 0; }
