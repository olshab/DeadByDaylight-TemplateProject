#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "Templates/SubclassOf.h"
#include "ECustomizationCategory.h"
#include "StoreCategoryViewData.h"
#include "StoreCharactersFiltersData.h"
#include "StoreCharactersSubPresenter.generated.h"

class UUserWidget;
class UStoreCharacterItemViewData;
class UStoreCustomizationItemViewData;

UCLASS(BlueprintType)
class DBDUIPRESENTERS_API UStoreCharactersSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> StoreCharactersWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName DisplayStandName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CameraTransitionDurationSeconds;

private:
	UPROPERTY(Transient)
	TArray<UStoreCharacterItemViewData*> _availableCharacters;

	UPROPERTY(Transient)
	UStoreCharacterItemViewData* _selectedCharacter;

	UPROPERTY(Transient)
	TArray<UStoreCustomizationItemViewData*> _availableCustomizations;

	UPROPERTY(Transient)
	TArray<UStoreCustomizationItemViewData*> _filteredCustomizations;

	UPROPERTY(Transient)
	TArray<FStoreCategoryViewData> _availableCategories;

	UPROPERTY(Transient)
	FStoreCharactersFiltersData _charactersFilterData;

	UPROPERTY(Transient)
	FStoreCharactersFiltersData _customizationsFilterData;

private:
	UFUNCTION()
	void OnDisplayStandPawnLoaded(int32 characterIndex);

	UFUNCTION()
	void OnCustomizationsFiltersChanged(FStoreCharactersFiltersData customizationsFilterData);

	UFUNCTION()
	void OnCustomizationSelected(FName customizationId, bool isSelected);

	UFUNCTION()
	void OnCustomizationsClearFiltersClicked();

	UFUNCTION()
	void OnCharactersFiltersChanged(FStoreCharactersFiltersData charactersFilterData);

	UFUNCTION()
	void OnCharacterSelected(int32 characterIndex);

	UFUNCTION()
	void OnCharactersClearFiltersClicked();

	UFUNCTION()
	void OnCategorySelected(ECustomizationCategory category);

public:
	UStoreCharactersSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreCharactersSubPresenter) { return 0; }
