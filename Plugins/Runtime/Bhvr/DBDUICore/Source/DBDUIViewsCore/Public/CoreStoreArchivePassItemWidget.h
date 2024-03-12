#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "StoreArchivePassViewData.h"
#include "CoreStoreArchivePassItemWidget.generated.h"

class UDBDImage;
class UCoreButtonWidget;
class UCoreOnHoverBorderWidget;
class UDBDTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreArchivePassItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDImage* IconIMG;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* SubTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreOnHoverBorderWidget* OnHoverBorder;

	UPROPERTY(BlueprintReadOnly, Transient)
	FStoreArchivePassViewData _viewData;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(const FStoreArchivePassViewData& data);

protected:
	UFUNCTION()
	void OnButtonUnhovered(UCoreButtonWidget* targetButton);

	UFUNCTION()
	void OnButtonHovered(UCoreButtonWidget* targetButton);

public:
	UCoreStoreArchivePassItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreArchivePassItemWidget) { return 0; }
