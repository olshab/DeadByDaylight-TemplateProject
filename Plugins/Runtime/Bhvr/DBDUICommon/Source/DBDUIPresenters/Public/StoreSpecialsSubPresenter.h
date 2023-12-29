#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "UObject/ScriptInterface.h"
#include "StoreSpecialsSubPresenter.generated.h"

class UStoreSpecialsItemViewData;
class IStoreSpecialsViewInterface;

UCLASS()
class DBDUIPRESENTERS_API UStoreSpecialsSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TScriptInterface<IStoreSpecialsViewInterface> _storeSpecialsWidget;

	UPROPERTY(Transient)
	TArray<UStoreSpecialsItemViewData*> _cachedSpecialsItems;

private:
	UFUNCTION()
	void OnPremiumTransactionCompleted(bool success);

	UFUNCTION()
	void OnAuricCellSpecialOtherOptions();

	UFUNCTION()
	void OnAuricCellSpecialBuyAction(FName bundleId);

public:
	UStoreSpecialsSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreSpecialsSubPresenter) { return 0; }
