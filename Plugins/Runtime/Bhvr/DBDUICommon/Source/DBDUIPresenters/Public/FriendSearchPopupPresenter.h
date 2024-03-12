#pragma once

#include "CoreMinimal.h"
#include "GenericPopupPresenter.h"
#include "FriendSearchPopupPresenter.generated.h"

UCLASS(EditInlineNew)
class UFriendSearchPopupPresenter : public UGenericPopupPresenter
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnSearchBarTextChanged(const FString& enteredText);

public:
	UFriendSearchPopupPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UFriendSearchPopupPresenter) { return 0; }
