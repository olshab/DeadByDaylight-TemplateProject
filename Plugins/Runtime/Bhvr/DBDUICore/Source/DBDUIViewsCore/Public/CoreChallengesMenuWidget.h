#pragma once

#include "CoreMinimal.h"
#include "BackButtonClickedDelegate.h"
#include "CoreBaseUserWidget.h"
#include "ChallengesMenuViewInterface.h"
#include "SettingsButtonClickedDelegate.h"
#include "ChallengesMenuTabSelectedDelegate.h"
#include "CoreChallengesMenuWidget.generated.h"

class UCoreTabContainerWidget;
class UCoreInputSwitcherWidget;
class UCoreSelectableButtonWidget;
class UCoreFooterInputSwitcherWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreChallengesMenuWidget : public UCoreBaseUserWidget, public IChallengesMenuViewInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Export)
	UCoreTabContainerWidget* TabsContainer;

	UPROPERTY(BlueprintReadWrite, Export)
	UCoreInputSwitcherWidget* BackInputSwitcher;

	UPROPERTY(BlueprintReadWrite, Export)
	UCoreFooterInputSwitcherWidget* SettingsInputSwitcher;

protected:
	UPROPERTY()
	FBackButtonClickedDelegate _backButtonClickedDelegate;

	UPROPERTY()
	FSettingsButtonClickedDelegate _settingsButtonClickedDelegate;

	UPROPERTY()
	FChallengesMenuTabSelectedDelegate _menuTabSelectedDelegate;

protected:
	UFUNCTION()
	void OnSettingsButtonClicked();

public:
	UFUNCTION()
	void OnMenuTabSelected(UCoreSelectableButtonWidget* selectedButton);

protected:
	UFUNCTION()
	void OnBackButtonClicked();

public:
	UCoreChallengesMenuWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreChallengesMenuWidget) { return 0; }
