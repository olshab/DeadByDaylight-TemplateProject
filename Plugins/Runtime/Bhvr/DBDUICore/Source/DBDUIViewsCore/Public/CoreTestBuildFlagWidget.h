#pragma once

#include "CoreMinimal.h"
#include "TestBuildFlagViewInterface.h"
#include "ETestBuildFlagPosition.h"
#include "CoreBaseHudWidget.h"
#include "CoreTestBuildFlagWidget.generated.h"

class UGridPanel;
class UCanvasPanel;
class UTextBlock;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreTestBuildFlagWidget : public UCoreBaseHudWidget, public ITestBuildFlagViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UCanvasPanel* ContainerCanvasPanel;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UGridPanel* TestFlagContainer;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* TopLineTextfield;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* BottomLineTextfield;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTestFlagPosition(ETestBuildFlagPosition testBuildFlagPosition);

public:
	UCoreTestBuildFlagWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreTestBuildFlagWidget) { return 0; }
