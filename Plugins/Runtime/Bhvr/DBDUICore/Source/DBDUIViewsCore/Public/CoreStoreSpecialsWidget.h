#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "StoreSpecialsViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "SpecialItemClickedDelegate.h"
#include "ArchivePassBannerClickedDelegate.h"
#include "CoreStoreSpecialsWidget.generated.h"

class UCorePreConstructableList;
class UCoreAuricCellsSpecialOfferWidget;
class UHorizontalBox;
class UCoreStoreSpecialsItemWidget;
class UDBDTextBlock;
class UOverlay;
class UCoreArchivePassBannerWidget;
class UDBDWrapBox;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class UCoreStoreSpecialsWidget : public UCoreBaseUserWidget, public IStoreSpecialsViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreStoreSpecialsItemWidget> _itemWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _layoutMask;

	UPROPERTY(EditAnywhere, NoClear)
	int32 _highlightPreConstructedItemsCount;

	UPROPERTY(EditAnywhere)
	float _highlightItemsScale;

	UPROPERTY(EditAnywhere, NoClear)
	int32 _regularPreConstructedItemsCount;

	UPROPERTY(EditAnywhere)
	float _regularItemsScale;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreAuricCellsSpecialOfferWidget* AuricCellSpecialOffer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* NoAuricCellsTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* NoAuricCellsTextTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* HighlightSectionTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UOverlay* ArchivePassBannerContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreArchivePassBannerWidget* ArchivePassBanner;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UHorizontalBox* HighlightSectionContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* RegularSectionTitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDWrapBox* RegularSectionContainer;

	UPROPERTY()
	FSpecialItemClickedDelegate SpecialItemClickedDelegate;

	UPROPERTY()
	FArchivePassBannerClickedDelegate ArchivePassBannerClickedDelegate;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _highlightItemList;

	UPROPERTY(Transient)
	UCorePreConstructableList* _regularItemList;

private:
	UFUNCTION()
	void OnSpecialItemClicked(UCoreButtonWidget* buttonTarget);

	UFUNCTION()
	void OnArchivePassBannerClicked(UCoreButtonWidget* buttonTarget);

public:
	UCoreStoreSpecialsWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreSpecialsWidget) { return 0; }
