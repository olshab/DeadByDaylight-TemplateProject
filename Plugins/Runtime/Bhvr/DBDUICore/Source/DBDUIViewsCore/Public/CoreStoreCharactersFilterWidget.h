#pragma once

#include "CoreMinimal.h"
#include "StoreCharactersFilterViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "OnClearFiltersClickedDelegate.h"
#include "OnStoreFiltersChangedDelegate.h"
#include "EItemFilterOption.h"
#include "CoreStoreCharactersFilterWidget.generated.h"

class UCoreButtonWidget;
class UPanelWidget;
class UCoreFilterButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreCharactersFilterWidget : public UCoreBaseUserWidget, public IStoreCharactersFilterViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreButtonWidget* ClearFiltersButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UPanelWidget* CheckBoxesContainer;

	UPROPERTY(BlueprintReadWrite, Transient, Export)
	TArray<UCoreFilterButtonWidget*> FiltersCheckBoxArray;

private:
	UPROPERTY()
	FOnClearFiltersClickedDelegate _onClearFiltersClicked;

	UPROPERTY()
	FOnStoreFiltersChangedDelegate _onFiltersChanged;

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ToggleWidgetVisibility();

	UFUNCTION(BlueprintCallable)
	void OnFilterOptionCheckBoxToggled(bool isToggled, EItemFilterOption itemFilterOption);

	UFUNCTION(BlueprintCallable)
	void OnClearFiltersClicked(UCoreButtonWidget* buttonTarget);

public:
	UCoreStoreCharactersFilterWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCharactersFilterWidget) { return 0; }
