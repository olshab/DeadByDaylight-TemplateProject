#pragma once

#include "CoreMinimal.h"
#include "PresenterParentWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "GridPresenterParentWidget.generated.h"

class UGridPanel;
class UImage;

UCLASS(EditInlineNew)
class UGridPresenterParentWidget : public UPresenterParentWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export)
	UGridPanel* Container;

	UPROPERTY(BlueprintReadOnly, Export)
	UImage* DividerImage;

public:
	UFUNCTION()
	void OnChildVisibilityChanged(ESlateVisibility InVisibility);

public:
	UGridPresenterParentWidget();
};

FORCEINLINE uint32 GetTypeHash(const UGridPresenterParentWidget) { return 0; }
