#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "NegatableDialogHandlerCondition.generated.h"

class UDialogHandlerCondition;

USTRUCT()
struct FNegatableDialogHandlerCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDialogHandlerCondition> ConditionClass;

	UPROPERTY(Transient)
	UDialogHandlerCondition* ConditionInstance;

	UPROPERTY(EditDefaultsOnly)
	bool IsNegated;

public:
	DEADBYDAYLIGHT_API FNegatableDialogHandlerCondition();
};

FORCEINLINE uint32 GetTypeHash(const FNegatableDialogHandlerCondition) { return 0; }
