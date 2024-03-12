#pragma once

#include "CoreMinimal.h"
#include "SubPresenter.h"
#include "UObject/ScriptInterface.h"
#include "ChallengesMenuEventRitualsRitualsSubPresenter.generated.h"

class IChallengesMenuEventRitualsRitualsViewInterface;

UCLASS()
class DBDUIPRESENTERS_API UChallengesMenuEventRitualsRitualsSubPresenter : public USubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TScriptInterface<IChallengesMenuEventRitualsRitualsViewInterface> _challengesMenuEventRitualsRitualsWidget;

public:
	UChallengesMenuEventRitualsRitualsSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UChallengesMenuEventRitualsRitualsSubPresenter) { return 0; }
