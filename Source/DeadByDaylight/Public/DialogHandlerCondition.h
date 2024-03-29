#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "GameEventData.h"
#include "DialogHandlerCondition.generated.h"

class ADBDGameState;

UCLASS(Blueprintable)
class DEADBYDAYLIGHT_API UDialogHandlerCondition : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	bool IsTrue(const FGameplayTag gameEventType, const FGameEventData& gameEventData, ADBDGameState* gameState);

public:
	UDialogHandlerCondition();
};

FORCEINLINE uint32 GetTypeHash(const UDialogHandlerCondition) { return 0; }
