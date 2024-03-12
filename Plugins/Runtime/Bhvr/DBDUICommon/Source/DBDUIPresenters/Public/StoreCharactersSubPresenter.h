#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "Templates/SubclassOf.h"
#include "EquippedPlayerCustomization.h"
#include "ESortingOption.h"
#include "ECustomizationCategory.h"
#include "StoreCategoryViewData.h"
#include "StoreCharactersFiltersData.h"
#include "AnimationPreviewRequest.h"
#include "ESortingOrder.h"
#include "ECurrencyType.h"
#include "StoreCharactersSubPresenter.generated.h"

class UUserWidget;
class UStoreCharacterItemViewData;
class UStoreCustomizationItemViewData;
class UAnimationPreviewSubsystem;

UCLASS(BlueprintType)
class DBDUIPRESENTERS_API UStoreCharactersSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> StoreCharactersWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName DisplayStandName;

private:
	UPROPERTY(Transient)
	TArray<UStoreCharacterItemViewData*> _availableCharacters;

	UPROPERTY(Transient)
	TArray<UStoreCharacterItemViewData*> _displayingCharacters;

	UPROPERTY(Transient)
	TMap<int32, UStoreCharacterItemViewData*> _charactersMap;

	UPROPERTY(Transient)
	TArray<UStoreCustomizationItemViewData*> _availableCustomizations;

	UPROPERTY(Transient)
	TArray<UStoreCustomizationItemViewData*> _displayingCustomizations;

	UPROPERTY(Transient)
	TMap<FName, UStoreCustomizationItemViewData*> _customizationsMap;

	UPROPERTY(Transient)
	FEquippedPlayerCustomization _equippedCustomization;

	UPROPERTY(Transient)
	FEquippedPlayerCustomization _selectedCustomization;

	UPROPERTY(Transient)
	TArray<FStoreCategoryViewData> _availableCategories;

	UPROPERTY(Transient)
	FStoreCharactersFiltersData _charactersFilterData;

	UPROPERTY(Transient)
	ESortingOption _charactersSortingOption;

	UPROPERTY(Transient)
	ESortingOrder _charactersSortingOrder;

	UPROPERTY(Transient)
	FStoreCharactersFiltersData _customizationsFilterData;

	UPROPERTY(Transient)
	ESortingOption _customizationsSortingOption;

	UPROPERTY(Transient)
	ESortingOrder _customizationsSortingOrder;

private:
	UFUNCTION()
	void PlayMoriAnimation();

	UFUNCTION()
	void OnZoomCharmClicked();

	UFUNCTION()
	void OnPresetSelected(const int32 presetId);

	UFUNCTION()
	void OnCustomizationUnlockCompleted(bool success);

	UFUNCTION()
	void OnCustomizationUnlockClicked(ECurrencyType currencyType);

	UFUNCTION()
	void OnCustomizationsSortingChanged(const ESortingOption sortingOption, const ESortingOrder sortingOrder);

	UFUNCTION()
	void OnCustomizationsFiltersChanged(const FStoreCharactersFiltersData& customizationsFilterData);

	UFUNCTION()
	void OnCustomizationSelected(const FName customizationId, const bool isSelected);

	UFUNCTION()
	void OnCustomizationSelectAllClicked();

	UFUNCTION()
	void OnCustomizationSearchBarTextChanged(const FString& enteredText);

	UFUNCTION()
	void OnCustomizationsClearFiltersClicked();

	UFUNCTION()
	void OnCustomizationEquipClicked();

	UFUNCTION()
	void OnCustomizationEquipAllClicked();

	UFUNCTION()
	void OnCustomizationAlternativeUnlockClicked();

	UFUNCTION()
	void OnCharmSlotSelected(const int32 slotIndex);

	UFUNCTION()
	void OnCharacterUnlockCompleted(bool success);

	UFUNCTION()
	void OnCharacterUnlockClicked(ECurrencyType currencyType);

	UFUNCTION()
	void OnCharactersSortingChanged(const ESortingOption sortingOption, const ESortingOrder sortingOrder);

	UFUNCTION()
	void OnCharactersSearchBarTextChanged(const FString& enteredText);

	UFUNCTION()
	void OnCharactersFiltersChanged(const FStoreCharactersFiltersData& charactersFilterData);

	UFUNCTION()
	void OnCharacterSelected(const int32 characterIndex);

	UFUNCTION()
	void OnCharactersClearFiltersClicked();

	UFUNCTION()
	void OnCharacterEquipClicked();

	UFUNCTION()
	void OnCharacterAlternativeUnlockClicked();

	UFUNCTION()
	void OnCategorySelected(const ECustomizationCategory category);

	UFUNCTION()
	void OnAnimationPreviewComplete(UAnimationPreviewSubsystem* animationPreviewSubsystem, const FAnimationPreviewRequest& request, bool completedSuccessfully);

public:
	UStoreCharactersSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreCharactersSubPresenter) { return 0; }
