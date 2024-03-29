#pragma once

#include "CoreMinimal.h"
#include "NegatableDialogHandlerCondition.h"
#include "DialogHandlerConditionContainer.generated.h"

USTRUCT()
struct FDialogHandlerConditionContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FNegatableDialogHandlerCondition> Conditions;

public:
	DEADBYDAYLIGHT_API FDialogHandlerConditionContainer();
};

FORCEINLINE uint32 GetTypeHash(const FDialogHandlerConditionContainer) { return 0; }
