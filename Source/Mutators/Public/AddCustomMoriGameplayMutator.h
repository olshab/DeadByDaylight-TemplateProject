#pragma once

#include "CoreMinimal.h"
#include "GameplayMutator.h"
#include "Templates/SubclassOf.h"
#include "AddCustomMoriGameplayMutator.generated.h"

class UInteractionDefinition;

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class UAddCustomMoriGameplayMutator : public UGameplayMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UInteractionDefinition> _customMori;

public:
	UAddCustomMoriGameplayMutator();
};

FORCEINLINE uint32 GetTypeHash(const UAddCustomMoriGameplayMutator) { return 0; }
