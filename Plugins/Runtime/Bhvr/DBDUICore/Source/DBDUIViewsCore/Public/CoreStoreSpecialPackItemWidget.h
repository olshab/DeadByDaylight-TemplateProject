#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "SpecialPackClickedDelegate.h"
#include "CoreStoreSpecialPackItemWidget.generated.h"

class UStoreChapterPackViewData;
class UCoreTimerFlagWidget;
class UCoreKeyListenerButtonWidget;
class UDBDTextBlock;
class UCoreOnHoverBorderWidget;
class UStoreSpecialPackViewData;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreSpecialPackItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSpecialPackClickedDelegate OnItemClicked;

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreOnHoverBorderWidget* OnHoverBorder;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* OwnedCountTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreTimerFlagWidget* TimerFlag;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreKeyListenerButtonWidget* SeeMoreButton;

private:
	UPROPERTY(Transient)
	FString _packId;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetSpecialPackData(UStoreSpecialPackViewData* data);

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetNewIcon(const bool isNew);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetChapterPackData(UStoreChapterPackViewData* data);

private:
	UFUNCTION()
	void OnPackClicked(UCoreButtonWidget* widget);

public:
	UCoreStoreSpecialPackItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreSpecialPackItemWidget) { return 0; }
