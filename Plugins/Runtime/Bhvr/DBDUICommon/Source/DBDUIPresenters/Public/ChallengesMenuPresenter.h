#pragma once

#include "CoreMinimal.h"
#include "EChallengesMenuState.h"
#include "UObject/SoftObjectPtr.h"
#include "Presenter.h"
#include "ChallengesMenuPresenter.generated.h"

class UChallengesMenuDailyRitualsSubPresenter;
class UChallengesMenuEventRitualsSubPresenter;
class UUserWidget;
class USubPresenter;

UCLASS(EditInlineNew)
class DBDUIPRESENTERS_API UChallengesMenuPresenter : public UPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UUserWidget> ChallengesMenuWidgetClass;

private:
	UPROPERTY(Transient)
	UChallengesMenuDailyRitualsSubPresenter* _dailyRitualsSubPresenter;

	UPROPERTY(Transient)
	UChallengesMenuEventRitualsSubPresenter* _eventRitualsSubPresenter;

	UPROPERTY(Transient)
	USubPresenter* _activeSubPresenter;

private:
	UFUNCTION()
	void SetMenuState(const EChallengesMenuState menuState);

	UFUNCTION()
	void OnSettingsButtonClicked();

	UFUNCTION()
	void OnBackButtonClicked();

public:
	UChallengesMenuPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UChallengesMenuPresenter) { return 0; }
