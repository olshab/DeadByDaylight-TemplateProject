#pragma once

#include "CoreMinimal.h"
#include "MainMenuViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "CoreMainMenuWidget.generated.h"

class UCoreMainMenuButtonWidget;
class UCoreButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreMainMenuWidget : public UCoreBaseUserWidget, public IMainMenuViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* PlayButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* PlayLimitedTimeEventButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* TutorialButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* ArchivesButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* StoreButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* PlayKillerButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* PlaySurvivorButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* PlayCustomGameButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* PlayLimitedTimeEventKillerButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* PlayLimitedTimeEventSurvivorButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreMainMenuButtonWidget* EventButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreButtonWidget* DailyRitualsButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreButtonWidget* FriendsButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreButtonWidget* SettingsButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreButtonWidget* NewsButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreButtonWidget* CreditsButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreButtonWidget* ExitButton;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowPlaySubMenu(bool open);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowLimitedTimeEventSubMenu(bool open);

private:
	UFUNCTION()
	void OnTutorialButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnStoreButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnSettingsButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnPlaySurvivorButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnPlayLimitedTimeEventSurvivorButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnPlayLimitedTimeEventKillerButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnPlayLimitedTimeEventButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnPlayKillerButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnPlayCustomButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnPlayButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnNewsButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnFriendsButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnExitButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnEventButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnDailyRitualsButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnCreditsButtonClicked(UCoreButtonWidget* target);

	UFUNCTION()
	void OnArchivesButtonClicked(UCoreButtonWidget* target);

public:
	UCoreMainMenuWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreMainMenuWidget) { return 0; }
