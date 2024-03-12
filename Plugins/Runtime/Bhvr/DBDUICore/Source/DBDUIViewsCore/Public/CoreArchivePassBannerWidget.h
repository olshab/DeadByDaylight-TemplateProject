#pragma once

#include "CoreMinimal.h"
#include "CoreButtonWidget.h"
#include "StoreArchivePassViewData.h"
#include "CoreArchivePassBannerWidget.generated.h"

class UDBDTextBlock;
class UCoreTimerFlagWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreArchivePassBannerWidget : public UCoreButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* SubTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreTimerFlagWidget* TimerFlag;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(const FStoreArchivePassViewData& data);

public:
	UCoreArchivePassBannerWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreArchivePassBannerWidget) { return 0; }
