#pragma once

#include "CoreMinimal.h"
#include "StoreCharactersViewInterface.h"
#include "CoreStoreBaseSubTabsWidget.h"
#include "CoreStoreCharactersWidget.generated.h"

class UDBDTextBlock;
class UCoreStoreCharacterPerksToastWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreStoreCharactersWidget : public UCoreStoreBaseSubTabsWidget, public IStoreCharactersViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDTextBlock* SelectedCharacterName;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCoreStoreCharacterPerksToastWidget* PerksToast;

public:
	UCoreStoreCharactersWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreCharactersWidget) { return 0; }
