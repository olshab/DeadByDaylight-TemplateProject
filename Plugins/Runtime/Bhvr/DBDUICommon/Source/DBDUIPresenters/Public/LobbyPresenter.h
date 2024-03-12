#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Presenter.h"
#include "LobbyPresenter.generated.h"

class ULobbySubPresenter;
class UUserWidget;
class ULobbyCharactersSubPresenter;

UCLASS(EditInlineNew)
class DBDUIPRESENTERS_API ULobbyPresenter : public UPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UUserWidget> LobbyWidgetClass;

private:
	UPROPERTY(Transient)
	ULobbySubPresenter* _activeSubPresenter;

	UPROPERTY(Transient)
	ULobbyCharactersSubPresenter* _charactersSubPresenter;

public:
	ULobbyPresenter();
};

FORCEINLINE uint32 GetTypeHash(const ULobbyPresenter) { return 0; }
