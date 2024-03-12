#pragma once

#include "CoreMinimal.h"
#include "CoreKeyListenerInputPromptWidget.h"
#include "PriceTagViewData.h"
#include "ECurrencyType.h"
#include "CoreCurrencyInputPromptWidget.generated.h"

class UCurveFloat;
class UCorePriceTagWidget;

UCLASS(EditInlineNew)
class UCoreCurrencyInputPromptWidget : public UCoreKeyListenerInputPromptWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCorePriceTagWidget* PriceTag;

	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* _chargeToUnlockCurve;

	UPROPERTY(EditAnywhere)
	float _chargeToUnlockDuration;

public:
	UFUNCTION(BlueprintCallable)
	void SetCurrencyData(const FPriceTagViewData& currencyData);

	UFUNCTION(BlueprintPure=false, BlueprintCallable)
	void SetBackgroundVisible(const bool showBackground) const;

	UFUNCTION(BlueprintPure)
	ECurrencyType GetCurrencyType() const;

public:
	UCoreCurrencyInputPromptWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreCurrencyInputPromptWidget) { return 0; }
