#pragma once

#include "CoreMinimal.h"
#include "FeaturedChapterPackClickedDelegate.h"
#include "CoreSelectableButtonWidget.h"
#include "CoreStoreFeaturedChapterPackWidget.generated.h"

class UStoreFeaturedChapterPackViewData;

UCLASS(EditInlineNew)
class UCoreStoreFeaturedChapterPackWidget : public UCoreSelectableButtonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FFeaturedChapterPackClickedDelegate OnFeaturedChapterPackClicked;

private:
	UPROPERTY(Transient)
	UStoreFeaturedChapterPackViewData* _cachedViewData;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetData(UStoreFeaturedChapterPackViewData* viewData);

public:
	UCoreStoreFeaturedChapterPackWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreFeaturedChapterPackWidget) { return 0; }
