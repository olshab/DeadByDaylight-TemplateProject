#pragma once

#include "CoreMinimal.h"
#include "CoreButtonWidget.h"
#include "EItemRarity.h"
#include "CoreFilterButtonWidget.generated.h"

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreFilterButtonWidget : public UCoreButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	bool _isAvailableOption;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	bool _isOwnedOption;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	EItemRarity _itemRarityFilterOption;

	UPROPERTY(BlueprintReadOnly)
	bool _isToggled;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	bool _defaultToggleState;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UpdateVisualState();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetupTextLabel(const FText& label);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetupOwnedTagLabel();

	UFUNCTION(BlueprintCallable)
	void SetToggledState(bool isToggled);

	UFUNCTION(BlueprintPure)
	bool IsToggled() const;

public:
	UCoreFilterButtonWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreFilterButtonWidget) { return 0; }
