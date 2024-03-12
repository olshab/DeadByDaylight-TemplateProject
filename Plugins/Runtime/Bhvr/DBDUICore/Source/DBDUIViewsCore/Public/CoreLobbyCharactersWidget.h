#pragma once

#include "CoreMinimal.h"
#include "LobbyCharactersViewInterface.h"
#include "LobbyCharactersTabSelectedDelegate.h"
#include "CoreBaseUserWidget.h"
#include "CoreLobbyCharactersWidget.generated.h"

class UWidgetSwitcher;
class UCoreTabContainerWidget;
class UCoreSelectableButtonWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreLobbyCharactersWidget : public UCoreBaseUserWidget, public ILobbyCharactersViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite)
	FLobbyCharactersTabSelectedDelegate _subTabSelectedDelegate;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetOptional))
	UWidgetSwitcher* WidgetSwitcher;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetOptional))
	UCoreTabContainerWidget* SubTabContainer;

private:
	UFUNCTION()
	void OnSubTabSelected(UCoreSelectableButtonWidget* selectedButton);

public:
	UCoreLobbyCharactersWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreLobbyCharactersWidget) { return 0; }
