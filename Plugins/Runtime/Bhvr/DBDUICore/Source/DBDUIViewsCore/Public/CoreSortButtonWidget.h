#pragma once

#include "CoreMinimal.h"
#include "CoreButtonWidget.h"
#include "CoreSortButtonWidget.generated.h"

class UDBDRichTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreSortButtonWidget : public UCoreButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDRichTextBlock* SortByRTB;

public:
	UCoreSortButtonWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreSortButtonWidget) { return 0; }
