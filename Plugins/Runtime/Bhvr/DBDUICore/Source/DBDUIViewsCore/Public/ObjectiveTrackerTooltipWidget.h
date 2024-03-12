#pragma once

#include "CoreMinimal.h"
#include "TooltipWidget.h"
#include "Templates/SubclassOf.h"
#include "EventObjectiveTrackerViewData.h"
#include "ObjectiveTrackerTooltipWidget.generated.h"

class UDBDImage;
class UVerticalBox;
class UObjectiveRewardLabelWidget;
class UDBDTextBlock;
class UDBDRichTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UObjectiveTrackerTooltipWidget : public UTooltipWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* TitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* SubtitleTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDRichTextBlock* DescriptionRTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* RewardsHeaderTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UVerticalBox* RewardLabelContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDImage* BannerIMG;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDImage* LabelIMG;

	UPROPERTY(EditDefaultsOnly, NoClear)
	TSubclassOf<UObjectiveRewardLabelWidget> ObjectiveRewardLabelWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 MaxRewardLabels;

private:
	UPROPERTY(Transient, Export)
	TArray<UObjectiveRewardLabelWidget*> _objectiveRewardWidgetPool;

public:
	UFUNCTION()
	void SetTooltipData(const FEventObjectiveTrackerViewData& viewData);

public:
	UObjectiveTrackerTooltipWidget();
};

FORCEINLINE uint32 GetTypeHash(const UObjectiveTrackerTooltipWidget) { return 0; }
