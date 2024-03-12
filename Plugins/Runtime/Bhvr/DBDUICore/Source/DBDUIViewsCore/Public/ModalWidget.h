#pragma once

#include "CoreMinimal.h"
#include "TooltipWidget.h"
#include "Input/Events.h"
#include "ModalWidget.generated.h"

class UDBDButton;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UModalWidget : public UTooltipWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDButton* HitzoneButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float _timeToFade;

protected:
	UFUNCTION(BlueprintNativeEvent)
	void StartOpenAnimation();

	UFUNCTION(BlueprintNativeEvent)
	void StartCloseAnimation();

	UFUNCTION()
	void OnUnhoveredInternal();

private:
	UFUNCTION()
	void OnMouseUpAnywhere(const FPointerEvent& pointerEvent);

	UFUNCTION()
	void OnMouseDownAnywhere(const FPointerEvent& pointerEvent);

protected:
	UFUNCTION()
	void OnHoveredInternal();

	UFUNCTION(BlueprintCallable)
	void FinishOpenAnimation();

	UFUNCTION(BlueprintCallable)
	void FinishCloseAnimation();

public:
	UModalWidget();
};

FORCEINLINE uint32 GetTypeHash(const UModalWidget) { return 0; }
