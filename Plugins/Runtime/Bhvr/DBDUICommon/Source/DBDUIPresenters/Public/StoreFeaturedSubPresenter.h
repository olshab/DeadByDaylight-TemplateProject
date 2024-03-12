#pragma once

#include "CoreMinimal.h"
#include "StoreRedirectionData.h"
#include "StoreSubPresenter.h"
#include "StoreFeaturedCharacterViewData.h"
#include "MysteryBoxStatus.h"
#include "StoreFeaturedSubPresenter.generated.h"

class UStoreCustomizationItemViewData;
class UStoreFeaturedChapterPackViewData;

UCLASS()
class DBDUIPRESENTERS_API UStoreFeaturedSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<UStoreCustomizationItemViewData*> _itemsViewData;

	UPROPERTY(Transient)
	TArray<FStoreFeaturedCharacterViewData> _charactersViewData;

	UPROPERTY(Transient)
	UStoreFeaturedChapterPackViewData* _chapterPackViewData;

private:
	UFUNCTION()
	void RequestMoveToCharactersPage(const FStoreRedirectionData& storeRedirectionData);

	UFUNCTION()
	void RequestMoveToChapterPacksPage(const FString& chapterPackId);

	UFUNCTION()
	void OnMysteryBoxStatusLoaded(bool succeeded, const FString& campaign, const FMysteryBoxStatus& status);

	UFUNCTION()
	void OnMysteryBoxClaimComplete(bool succeeded, const FString& campaign, const FMysteryBoxStatus& status);

	UFUNCTION()
	void OnMysteryBoxClaimClicked();

	UFUNCTION()
	void OnMysteryBoxClaimableStatusChanged(const FString& campaign, const FMysteryBoxStatus& status);

public:
	UFUNCTION()
	void OnBackendStoreDataReceived(bool success);

public:
	UStoreFeaturedSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreFeaturedSubPresenter) { return 0; }
