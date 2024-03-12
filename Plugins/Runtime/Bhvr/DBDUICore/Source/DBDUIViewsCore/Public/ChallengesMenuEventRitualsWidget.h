#pragma once

#include "CoreMinimal.h"
#include "ChallengesMenuEventRitualsViewInterface.h"
#include "CoreTabContentWidget.h"
#include "ChallengesMenuEventRitualsTabSelectedDelegate.h"
#include "ChallengesMenuEventRitualsWidget.generated.h"

class UCoreSelectableButtonWidget;
class UCoreTabContainerWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UChallengesMenuEventRitualsWidget : public UCoreTabContentWidget, public IChallengesMenuEventRitualsViewInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Export)
	UCoreTabContainerWidget* TabsContainer;

protected:
	UPROPERTY()
	FChallengesMenuEventRitualsTabSelectedDelegate _eventRitualsTabSelectedDelegate;

public:
	UFUNCTION()
	void OnEventRitualsTabSelected(UCoreSelectableButtonWidget* selectedButton);

public:
	UChallengesMenuEventRitualsWidget();
};

FORCEINLINE uint32 GetTypeHash(const UChallengesMenuEventRitualsWidget) { return 0; }
