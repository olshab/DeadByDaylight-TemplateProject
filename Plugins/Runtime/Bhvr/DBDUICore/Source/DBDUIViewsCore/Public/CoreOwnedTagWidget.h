#pragma once

#include "CoreMinimal.h"
#include "CoreBaseUserWidget.h"
#include "CoreOwnedTagWidget.generated.h"

class UDBDTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreOwnedTagWidget : public UCoreBaseUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetOptional))
	UDBDTextBlock* OwnedTB;

public:
	UCoreOwnedTagWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreOwnedTagWidget) { return 0; }
