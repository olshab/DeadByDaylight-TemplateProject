#pragma once

#include "CoreMinimal.h"
#include "AnimationPreviewViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "CoreAnimationPreviewWidget.generated.h"

class UDBDTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreAnimationPreviewWidget : public UCoreBaseUserWidget, public IAnimationPreviewViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDTextBlock* PressAnyButtonText;

public:
	UCoreAnimationPreviewWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreAnimationPreviewWidget) { return 0; }
