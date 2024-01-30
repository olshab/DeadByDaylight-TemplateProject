#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "StoreHeritagePackViewData.h"
#include "CoreStoreHeritagePackItemWidget.generated.h"

class UDBDTextBlock;
class UCorePremiumCurrencyButtonWidget;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreHeritagePackItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* ContentDescriptionTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCorePremiumCurrencyButtonWidget* PremiumBuyButton;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(const FStoreHeritagePackViewData& data);

protected:
	UFUNCTION()
	void OnBuyButtonClicked(UCoreButtonWidget* button);

public:
	UCoreStoreHeritagePackItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreHeritagePackItemWidget) { return 0; }
