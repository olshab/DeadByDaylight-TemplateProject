#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "CoreStoreEmptyItemWidget.generated.h"

class UCoreOnHoverBorderWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreEmptyItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreOnHoverBorderWidget* OnHoverBorder;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetEmptyItemData(const TArray<FName>& equippedCustomizationIds);

public:
	UCoreStoreEmptyItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreEmptyItemWidget) { return 0; }
