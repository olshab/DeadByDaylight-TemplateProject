#pragma once

#include "CoreMinimal.h"
#include "EChallengesMenuEventRitualsState.h"
#include "SubPresenter.h"
#include "UObject/ScriptInterface.h"
#include "ChallengesMenuEventRitualsSubPresenter.generated.h"

class UChallengesMenuEventRitualsRitualsSubPresenter;
class IChallengesMenuEventRitualsViewInterface;
class UChallengesMenuEventRitualsRewardTrackSubPresenter;
class UChallengesMenuEventRitualsStoreSubPresenter;

UCLASS()
class DBDUIPRESENTERS_API UChallengesMenuEventRitualsSubPresenter : public USubPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UChallengesMenuEventRitualsRitualsSubPresenter* _ritualsSubPresenter;

	UPROPERTY(Transient)
	UChallengesMenuEventRitualsRewardTrackSubPresenter* _rewardTrackSubPresenter;

	UPROPERTY(Transient)
	UChallengesMenuEventRitualsStoreSubPresenter* _storeSubPresenter;

	UPROPERTY(Transient)
	USubPresenter* _activeSubPresenter;

	UPROPERTY(Transient)
	TScriptInterface<IChallengesMenuEventRitualsViewInterface> _challengesMenuEventRitualsWidget;

private:
	UFUNCTION()
	void SetEventRitualsState(const EChallengesMenuEventRitualsState eventRitualsState);

public:
	UChallengesMenuEventRitualsSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UChallengesMenuEventRitualsSubPresenter) { return 0; }
