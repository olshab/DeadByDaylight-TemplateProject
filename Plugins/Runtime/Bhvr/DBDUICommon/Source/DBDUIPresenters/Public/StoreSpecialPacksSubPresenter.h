#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "StoreHeritagePackViewData.h"
#include "StoreSpecialPacksSubPresenter.generated.h"

class UStoreSpecialPackViewData;
class UStoreChapterPackViewData;

UCLASS()
class DBDUIPRESENTERS_API UStoreSpecialPacksSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<UStoreSpecialPackViewData*> _specialPacks;

	UPROPERTY(Transient)
	TArray<UStoreChapterPackViewData*> _chapterPacks;

	UPROPERTY(Transient)
	TArray<FStoreHeritagePackViewData> _heritagePacks;

private:
	UFUNCTION()
	void OnSpecialPackClicked(const FString& packId);

	UFUNCTION()
	void OnPackBuyClicked(const FString& packId);

	UFUNCTION()
	void OnHeritagePackBuyClicked(const FString& packId);

	UFUNCTION()
	void OnCustomizationClicked(const FString& packId, const FName& customizationId);

	UFUNCTION()
	void OnCharacterClicked(const FString& packId, const int32 characterIndex);

	UFUNCTION()
	void OnChapterPackClicked(const FString& packId);

	UFUNCTION()
	void OnArchivePassClicked(const FString& packId, const FName& archiveId);

public:
	UStoreSpecialPacksSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreSpecialPacksSubPresenter) { return 0; }
