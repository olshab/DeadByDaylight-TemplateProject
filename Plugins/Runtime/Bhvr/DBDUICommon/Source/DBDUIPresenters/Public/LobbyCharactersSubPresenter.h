#pragma once

#include "CoreMinimal.h"
#include "LobbySubPresenter.h"
#include "ELobbyCharactersMenuState.h"
#include "LobbyCharactersSubPresenter.generated.h"

UCLASS()
class DBDUIPRESENTERS_API ULobbyCharactersSubPresenter : public ULobbySubPresenter
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnSubTabSelected(ELobbyCharactersMenuState selectedTabId);

public:
	ULobbyCharactersSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const ULobbyCharactersSubPresenter) { return 0; }
