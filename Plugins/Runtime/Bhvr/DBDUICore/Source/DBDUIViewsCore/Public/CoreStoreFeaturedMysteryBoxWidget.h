#pragma once

#include "CoreMinimal.h"
#include "CoreSelectableButtonWidget.h"
#include "StoreMysteryBoxViewData.h"
#include "MysteryBoxClaimClickedDelegate.h"
#include "CoreStoreFeaturedMysteryBoxWidget.generated.h"

class UCoreButtonWidget;
class UDBDImage;
class UDBDTextBlock;

UCLASS(EditInlineNew)
class UCoreStoreFeaturedMysteryBoxWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FMysteryBoxClaimClickedDelegate OnMysteryBoxClaimClicked;

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreButtonWidget* ClaimButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* RewardAmountText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* LastRewardText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* LastRewardAmountText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDImage* LastRewardIconImage;

private:
	UPROPERTY()
	FStoreMysteryBoxViewData _cachedViewData;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(const FStoreMysteryBoxViewData& viewData);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void PresentClaimResult(bool succeeded, const FStoreMysteryBoxViewData& viewData);

private:
	UFUNCTION()
	void OnClaimButtonClicked(UCoreButtonWidget* buttonTarget);

public:
	UFUNCTION(BlueprintPure)
	FStoreMysteryBoxViewData GetMysteryBoxViewData() const;

public:
	UCoreStoreFeaturedMysteryBoxWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreFeaturedMysteryBoxWidget) { return 0; }
