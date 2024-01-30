#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "StoreArchivePassViewData.h"
#include "CoreStoreArchivePassItemWidget.generated.h"

class UDBDImage;
class UCoreOnHoverBorderWidget;
class UDBDTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreArchivePassItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDImage* IconIMG;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* SubTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreOnHoverBorderWidget* OnHoverBorder;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(const FStoreArchivePassViewData& data);

public:
	UCoreStoreArchivePassItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreArchivePassItemWidget) { return 0; }
