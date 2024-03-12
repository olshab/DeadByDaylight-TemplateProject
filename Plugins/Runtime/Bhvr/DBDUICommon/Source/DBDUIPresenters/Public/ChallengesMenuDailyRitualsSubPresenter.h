#pragma once

#include "CoreMinimal.h"
#include "SubPresenter.h"
#include "UObject/ScriptInterface.h"
#include "ChallengesMenuDailyRitualsSubPresenter.generated.h"

class IChallengesMenuDailyRitualsViewInterface;

UCLASS()
class DBDUIPRESENTERS_API UChallengesMenuDailyRitualsSubPresenter : public USubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TScriptInterface<IChallengesMenuDailyRitualsViewInterface> _challengesMenuDailyRitualsWidget;

public:
	UChallengesMenuDailyRitualsSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UChallengesMenuDailyRitualsSubPresenter) { return 0; }
