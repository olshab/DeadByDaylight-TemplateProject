#pragma once

#include "CoreMinimal.h"
#include "CoreBaseUserWidget.h"
#include "StoreFeaturedViewInterface.h"
#include "CoreStoreFeaturedWidget.generated.h"

class UCoreStoreFeaturedMysteryBoxWidget;
class UStoreCustomizationItemViewData;
class UCoreStoreFeaturedCustomizationItemContainerWidget;
class UCoreStoreFeaturedCharacterContainerWidget;
class UCoreStoreFeaturedChapterPackWidget;

UCLASS(EditInlineNew)
class UCoreStoreFeaturedWidget : public UCoreBaseUserWidget, public IStoreFeaturedViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient)
	TArray<UStoreCustomizationItemViewData*> _featuredItems;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreFeaturedCustomizationItemContainerWidget* CustomizationItemContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreFeaturedCharacterContainerWidget* CharacterContainer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreFeaturedMysteryBoxWidget* MysteryBox;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreStoreFeaturedChapterPackWidget* FeaturedChapterPack;

public:
	UCoreStoreFeaturedWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreFeaturedWidget) { return 0; }
