#pragma once

#include "CoreMinimal.h"
#include "ECollectionItemScaleType.h"
#include "CoreBaseUserWidget.h"
#include "CoreStoreCollectionsItemWidget.generated.h"

class UStoreCollectionViewData;
class UDBDTextBlock;
class UDBDButton;

UCLASS(EditInlineNew)
class UCoreStoreCollectionsItemWidget : public UCoreBaseUserWidget
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBannerClickedDelegate, const UStoreCollectionViewData*, collectionViewData);

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* CountTB;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDButton* BannerButton;

private:
	UPROPERTY(Transient)
	UStoreCollectionViewData* _collectionViewData;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetupVisuals(UStoreCollectionViewData* collectionViewData, const ECollectionItemScaleType collectionItemScale);

	UFUNCTION(BlueprintCallable)
	void SetData(UStoreCollectionViewData* collectionViewData, const ECollectionItemScaleType collectionItemScale);

protected:
	UFUNCTION()
	void OnBannerButtonClicked();

public:
	UCoreStoreCollectionsItemWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCollectionsItemWidget) { return 0; }
