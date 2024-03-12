#pragma once

#include "CoreMinimal.h"
#include "Presenter.h"
#include "Templates/SubclassOf.h"
#include "MatchmakingFlowPresenter.generated.h"

class UUserWidget;

UCLASS(EditInlineNew)
class UMatchmakingFlowPresenter : public UPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> MatchmakingWidgetClass;

public:
	UMatchmakingFlowPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UMatchmakingFlowPresenter) { return 0; }
