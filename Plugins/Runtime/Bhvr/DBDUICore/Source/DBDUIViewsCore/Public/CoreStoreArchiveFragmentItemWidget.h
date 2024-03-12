#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "StoreArchiveFragmentViewData.h"
#include "CoreStoreArchiveFragmentItemWidget.generated.h"

class UDBDImage;
class UCoreButtonWidget;
class UCoreOnHoverBorderWidget;
class UDBDTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreArchiveFragmentItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDImage* IconIMG;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* AmountTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreOnHoverBorderWidget* OnHoverBorder;

	UPROPERTY(BlueprintReadOnly, Transient)
	FStoreArchiveFragmentViewData _viewData;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(const FStoreArchiveFragmentViewData& data);

protected:
	UFUNCTION()
	void OnButtonUnhovered(UCoreButtonWidget* targetButton);

	UFUNCTION()
	void OnButtonHovered(UCoreButtonWidget* targetButton);

public:
	UCoreStoreArchiveFragmentItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreArchiveFragmentItemWidget) { return 0; }
