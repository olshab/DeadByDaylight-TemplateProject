#pragma once

#include "CoreMinimal.h"
#include "EStoreMenuState.h"
#include "ECurrencyType.h"
#include "UObject/SoftObjectPtr.h"
#include "Presenter.h"
#include "StoreMenuPresenter.generated.h"

class UStoreSpecialPacksSubPresenter;
class UStoreCollectionsSubPresenter;
class UShopManager;
class UStoreCharactersSubPresenter;
class UStoreSpecialsSubPresenter;
class UUserWidget;
class UStoreFeaturedSubPresenter;
class UStoreSubPresenter;
class UMatchmakingMonitor;
class USubPresenter;

UCLASS(EditInlineNew)
class DBDUIPRESENTERS_API UStoreMenuPresenter : public UPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UUserWidget> StoreMenuWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName DisplayStandName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InStoreCameraTransitionDurationSeconds;

private:
	UPROPERTY(Transient)
	UStoreFeaturedSubPresenter* _storeFeaturedSubPresenter;

	UPROPERTY(Transient)
	UStoreSpecialsSubPresenter* _storeSpecialsSubPresenter;

	UPROPERTY(Transient)
	UStoreCollectionsSubPresenter* _storeCollectionsSubPresenter;

	UPROPERTY(Transient)
	UStoreSpecialPacksSubPresenter* _storeSpecialPacksSubPresenter;

	UPROPERTY(Transient)
	UStoreCharactersSubPresenter* _storeKillersSubPresenter;

	UPROPERTY(Transient)
	UStoreCharactersSubPresenter* _storeSurvivorsSubPresenter;

	UPROPERTY(Transient)
	UStoreSubPresenter* _activeSubPresenter;

	UPROPERTY(Transient)
	UShopManager* _shopManager;

	UPROPERTY(Transient)
	UMatchmakingMonitor* _matchmakingMonitor;

private:
	UFUNCTION()
	void ShowArchivePassPopup(const FName& archiveId);

	UFUNCTION()
	void ResetBackActionLabel() const;

	UFUNCTION()
	void OpenRedeemCodePopup();

	UFUNCTION()
	void OpenAuricCellsOverlay();

	UFUNCTION()
	void OnStopSubPresenterAsyncOperation(USubPresenter* subPresenter);

	UFUNCTION()
	void OnStartSubPresenterAsyncOperation(USubPresenter* subPresenter);

	UFUNCTION()
	void OnNotEnoughCurrencyModalButtonClicked(const ECurrencyType currencyType);

	UFUNCTION()
	void OnMenuTabSelected(EStoreMenuState menuState);

	UFUNCTION()
	void OnBackActionLabelChangeRequested(const FText& newLabel) const;

	UFUNCTION()
	void OnBackAction();

	UFUNCTION()
	void OnAsyncLoadSuccess();

public:
	UStoreMenuPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreMenuPresenter) { return 0; }
