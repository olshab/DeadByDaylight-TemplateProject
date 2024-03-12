#pragma once

#include "CoreMinimal.h"
#include "TooltipWidget.h"
#include "Templates/SubclassOf.h"
#include "CustomizationTooltipViewData.h"
#include "CustomizationTooltipWidget.generated.h"

class UCoreCustomizationRewardWidget;
class UUniformGridPanel;
class UDBDTextBlock;
class UDBDRichTextBlock;
class UCorePreConstructableList;
class UCustomizationRewardOutfitPartsViewData;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCustomizationTooltipWidget : public UTooltipWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreCustomizationRewardWidget> _outfitPartWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	int32 _preConstructedOutfitPartsCount;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* ToolTipStatusTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDRichTextBlock* ToolTipDescriptionRTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUniformGridPanel* OutfitPartsContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* OutfitPartsLabel;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _outfitPartsList;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetTooltipData(const FCustomizationTooltipViewData& customizationViewData);

protected:
	UFUNCTION(BlueprintCallable)
	void SetStatusText(const bool isEquipped, const bool isOwned, const bool isLocked);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetOutfitParts(const UCustomizationRewardOutfitPartsViewData* outfitPartsViewData);

public:
	UFUNCTION()
	void AppendToDescriptionText(const FText& appendedText);

public:
	UCustomizationTooltipWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCustomizationTooltipWidget) { return 0; }
