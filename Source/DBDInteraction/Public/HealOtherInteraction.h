#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HealInteraction.h"
#include "HealOtherInteraction.generated.h"

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class DBDINTERACTION_API UHealOtherInteraction : public UHealInteraction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	FVector SlashableRelativeLocationInjured;

	UPROPERTY(EditDefaultsOnly)
	FVector SlashableRelativeLocationKO;

public:
	UHealOtherInteraction();
};

FORCEINLINE uint32 GetTypeHash(const UHealOtherInteraction) { return 0; }
