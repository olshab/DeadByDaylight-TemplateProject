#pragma once

#include "CoreMinimal.h"
#include "Layout/Geometry.h"
#include "ArchiveNodeViewData.h"
#include "CustomizationTooltipViewData.h"
#include "ArchiveRewardNodeTooltipViewData.h"
#include "ETooltipType.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CorePlayerLevelTooltipViewData.h"
#include "RankTooltipViewData.h"
#include "ETooltipHorizontalAlignment.h"
#include "ETooltipVerticalAlignment.h"
#include "LockedFeatureTooltipViewData.h"
#include "EventObjectiveTrackerViewData.h"
#include "NotEnoughCurrencyModalViewData.h"
#include "LoadoutTooltipData.h"
#include "CurrencyProgressionTooltipViewData.h"
#include "CharacterTooltipViewData.h"
#include "ArchivePassTooltipViewData.h"
#include "CompendiumButtonData.h"
#include "DBDTooltipManager.generated.h"

class UUserWidget;
class UTooltipRoot;

UCLASS(BlueprintType)
class DBDUIVIEWSCORE_API UDBDTooltipManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export)
	UTooltipRoot* _rootWidget;

	UPROPERTY(Transient, Export)
	TMap<ETooltipType, UUserWidget*> _tooltipPool;

	UPROPERTY(Transient, Export)
	UUserWidget* _currentTooltip;

public:
	UFUNCTION(BlueprintCallable)
	void ShowRankTooltip(const FRankTooltipViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, const ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerLevelTooltip(const FCorePlayerLevelTooltipViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowObjectiveTrackerTooltip(const FEventObjectiveTrackerViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowNotEnoughCurrencyModal(const FNotEnoughCurrencyModalViewData& viewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, const ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowLockedFeatureTooltip(const FLockedFeatureTooltipViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, const ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowLoadoutTooltip(const FLoadoutTooltipData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowLabelTooltip(const FText& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowCustomizationTooltip(const FCustomizationTooltipViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowCurrencyTooltip(const FCurrencyProgressionTooltipViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowCharacterTooltip(const FCharacterTooltipViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowArchiveRewardNodeTooltip(const FArchiveRewardNodeTooltipViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowArchivePassTooltip(const FArchivePassTooltipViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, const ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowArchiveNodeTooltip(const FArchiveNodeViewData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void ShowArchiveCompendiumTooltip(const FCompendiumButtonData& tooltipViewData, const FGeometry& triggerGeometry, const ETooltipHorizontalAlignment tooltipHorizontalAlignment, ETooltipVerticalAlignment tooltipVerticalAlignment);

private:
	UFUNCTION()
	void OnViewportCreated();

public:
	UFUNCTION(BlueprintCallable)
	void HideTooltip();

public:
	UDBDTooltipManager();
};

FORCEINLINE uint32 GetTypeHash(const UDBDTooltipManager) { return 0; }
