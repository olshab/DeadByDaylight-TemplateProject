#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "Templates/SubclassOf.h"
#include "StoreSpecialPacksSubPresenter.generated.h"

class UUserWidget;
class UStoreSpecialPackViewData;
class UStoreChapterPackViewData;

UCLASS(BlueprintType)
class DBDUIPRESENTERS_API UStoreSpecialPacksSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> StoreBundlesWidgetClass;

private:
	UPROPERTY(Transient)
	TArray<UStoreSpecialPackViewData*> _specialPacks;

	UPROPERTY(Transient)
	TArray<UStoreChapterPackViewData*> _chapterPacks;

private:
	UFUNCTION()
	void OnSpecialPackBuyClicked(const FString& packId);

public:
	UStoreSpecialPacksSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreSpecialPacksSubPresenter) { return 0; }
