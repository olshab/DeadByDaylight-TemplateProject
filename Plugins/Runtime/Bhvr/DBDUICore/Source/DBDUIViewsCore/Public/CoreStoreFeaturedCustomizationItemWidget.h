#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CoreSelectableButtonWidget.h"
#include "OnMoveToCharactersCustomizationPageButtonClickedDelegate.h"
#include "CoreStoreFeaturedCustomizationItemWidget.generated.h"

class UCorePriceTagWidget;
class UStoreCustomizationItemViewData;
class UUITweenInstance;
class UHorizontalBox;
class UCorePreConstructableList;

UCLASS(EditInlineNew)
class UCoreStoreFeaturedCustomizationItemWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnMoveToCharactersCustomizationPageButtonClickedDelegate OnMoveToCharactersCustomizationPageButtonClickedDelegate;

protected:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCorePriceTagWidget> _priceTagWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 _preConstructedPriceTagCount;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UHorizontalBox* PriceTagsContainer;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _priceTagsList;

	UPROPERTY(Transient)
	UUITweenInstance* _sizeTween;

	UPROPERTY(Transient)
	UUITweenInstance* _positionTween;

private:
	UFUNCTION()
	void UpdateSize(UUITweenInstance* tween);

	UFUNCTION()
	void UpdatePosition(UUITweenInstance* tween);

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetCustomizationData(UStoreCustomizationItemViewData* customizationItemViewData);

protected:
	UFUNCTION(BlueprintCallable)
	UCorePriceTagWidget* CreatePriceTagWidget();

	UFUNCTION(BlueprintCallable)
	void ClearPriceTagWidgets();

public:
	UCoreStoreFeaturedCustomizationItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreFeaturedCustomizationItemWidget) { return 0; }
