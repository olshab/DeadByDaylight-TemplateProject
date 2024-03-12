#pragma once

#include "CoreMinimal.h"
#include "ESortingOrder.h"
#include "StoreSubPresenter.h"
#include "StoreCharactersFiltersData.h"
#include "ECurrencyType.h"
#include "ESortingOption.h"
#include "StoreCollectionsCustomizationsSubPresenter.generated.h"

class UStoreCollectionViewData;
class UStoreCustomizationItemViewData;

UCLASS()
class DBDUIPRESENTERS_API UStoreCollectionsCustomizationsSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UStoreCollectionViewData* _currentCollection;

	UPROPERTY(Transient)
	UStoreCustomizationItemViewData* _currentCustomization;

	UPROPERTY(Transient)
	TArray<UStoreCustomizationItemViewData*> _collectionCustomizations;

	UPROPERTY(Transient)
	TArray<UStoreCustomizationItemViewData*> _displayingCustomizations;

private:
	UFUNCTION()
	void UpdateDisplayingCustomizations();

	UFUNCTION()
	void OnSortingChanged(const ESortingOption sortingType, const ESortingOrder sortingOrder);

	UFUNCTION()
	void OnSearchBarTextChanged(const FString& searchString);

	UFUNCTION()
	void OnFiltersChanged(const FStoreCharactersFiltersData& storeFiltersData);

	UFUNCTION()
	void OnCustomizationUnlockClicked(ECurrencyType currencyType);

	UFUNCTION()
	void OnCustomizationSelected(const FName customizationId, const bool isSelected);

	UFUNCTION()
	void OnCustomizationEquipClicked();

	UFUNCTION()
	void OnClearFiltersClicked();

public:
	UStoreCollectionsCustomizationsSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreCollectionsCustomizationsSubPresenter) { return 0; }
