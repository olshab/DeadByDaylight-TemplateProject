#pragma once

#include "CoreMinimal.h"
#include "FriendSearchPopupViewInterface.h"
#include "CoreGenericPopupWidget.h"
#include "UObject/ScriptInterface.h"
#include "Templates/SubclassOf.h"
#include "FriendSearchPopupWidget.generated.h"

class UCoreInputSwitcherWidget;
class UCoreSearchBarWidget;
class UDBDScrollBox;
class ISearchBarViewInterface;
class UCoreButtonWidget;
class UFriendItemWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UFriendSearchPopupWidget : public UCoreGenericPopupWidget, public IFriendSearchPopupViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UCoreInputSwitcherWidget* FriendSearchWidget;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDScrollBox* FriendSearchScrollBox;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UFriendItemWidget> FriendItemWidgetClass;

	UPROPERTY(Export)
	TMap<FString, UFriendItemWidget*> _friendsMap;

	UPROPERTY()
	TScriptInterface<ISearchBarViewInterface> _searchBar;

	UPROPERTY(meta=(BindWidgetOptional))
	UCoreSearchBarWidget* SearchBar;

protected:
	UFUNCTION()
	void OnFriendClicked(UCoreButtonWidget* buttonTarget);

public:
	UFriendSearchPopupWidget();
};

FORCEINLINE uint32 GetTypeHash(const UFriendSearchPopupWidget) { return 0; }
