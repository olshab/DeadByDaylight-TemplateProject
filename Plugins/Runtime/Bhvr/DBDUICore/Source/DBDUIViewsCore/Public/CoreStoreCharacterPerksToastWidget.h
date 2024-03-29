#pragma once

#include "CoreMinimal.h"
#include "CoreBaseUserWidget.h"
#include "EPlayerRole.h"
#include "Input/Events.h"
#include "CoreStoreCharacterPerksToastWidget.generated.h"

class UCoreMenuPowerWidget;
class UMenuPowerViewData;
class UWidget;
class UDBDTextBlock;
class UCoreMenuPerkWidget;
class UCoreButtonWidget;
class UCharacterPerkViewData;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreCharacterPerksToastWidget : public UCoreBaseUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* Title;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreMenuPowerWidget* CoreKillerPower;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreMenuPerkWidget* CorePerk_1;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreMenuPerkWidget* CorePerk_2;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreMenuPerkWidget* CorePerk_3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export)
	TArray<UWidget*> _ignoreClickWidgets;

	UPROPERTY(BlueprintReadOnly)
	bool _isOpen;

public:
	UFUNCTION(BlueprintCallable)
	void ToggleToastVisibility();

private:
	UFUNCTION(BlueprintCallable)
	void ShowTooltip(UCoreButtonWidget* hoveredSlotWidget);

protected:
	UFUNCTION(BlueprintCallable)
	void SetPerkData(UCoreMenuPerkWidget* perkWidget, UCharacterPerkViewData* perkViewData);

public:
	UFUNCTION(BlueprintPure=false, BlueprintCallable)
	void SetKillerPowerData(const UMenuPowerViewData* killerPowerViewData) const;

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetCharacterRole(EPlayerRole role);

public:
	UFUNCTION(BlueprintCallable)
	void SetCharacterData(TArray<UCharacterPerkViewData*> characterUniquePerksViewData, EPlayerRole role);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OpenToast(bool isOpen);

private:
	UFUNCTION()
	void OnPlayerClick(const FPointerEvent& pointerEvent);

	UFUNCTION(BlueprintCallable)
	void HideTooltip(UCoreButtonWidget* unhoveredSlotWidget);

public:
	UCoreStoreCharacterPerksToastWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCharacterPerksToastWidget) { return 0; }
