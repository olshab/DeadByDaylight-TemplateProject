#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSQuestEventsHandlerComponent.generated.h"

class UQuestEventEvaluatorBase;

UCLASS(meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API UDSQuestEventsHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<UQuestEventEvaluatorBase*> _evaluatorList;

public:
	UDSQuestEventsHandlerComponent();
};

FORCEINLINE uint32 GetTypeHash(const UDSQuestEventsHandlerComponent) { return 0; }
