#pragma once

#include "CoreMinimal.h"
#include "SubPresenter.h"
#include "UObject/ScriptInterface.h"
#include "ChallengesMenuEventRitualsRewardTrackSubPresenter.generated.h"

class IChallengesMenuEventRitualsRewardTrackViewInterface;

UCLASS()
class DBDUIPRESENTERS_API UChallengesMenuEventRitualsRewardTrackSubPresenter : public USubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TScriptInterface<IChallengesMenuEventRitualsRewardTrackViewInterface> _challengesMenuEventRitualsRewardTrackWidget;

public:
	UChallengesMenuEventRitualsRewardTrackSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UChallengesMenuEventRitualsRewardTrackSubPresenter) { return 0; }
