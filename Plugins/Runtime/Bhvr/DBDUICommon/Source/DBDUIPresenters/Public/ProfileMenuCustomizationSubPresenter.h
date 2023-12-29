#pragma once

#include "CoreMinimal.h"
#include "SubPresenter.h"
#include "EItemSorting.h"
#include "UObject/ScriptInterface.h"
#include "ProfileMenuCustomizationSubPresenter.generated.h"

class IProfileMenuCustomizationViewInterface;

UCLASS()
class DBDUIPRESENTERS_API UProfileMenuCustomizationSubPresenter : public USubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TScriptInterface<IProfileMenuCustomizationViewInterface> _profileMenuCustomizationWidget;

private:
	UFUNCTION()
	void OnRewardGridItemClicked(const int32 selectedIndex);

	UFUNCTION()
	void OnEquipButtonClicked();

	UFUNCTION()
	void OnCustomizationSortingChanged(const EItemSorting itemSorting);

public:
	UProfileMenuCustomizationSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UProfileMenuCustomizationSubPresenter) { return 0; }
