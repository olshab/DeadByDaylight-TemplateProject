#pragma once

#include "CoreMinimal.h"
#include "HideInTerrorRadiusQEEvaluator.h"
#include "GameplayTagContainer.h"
#include "HideInTerrorRadiusWithStateTagQEEvaluator.generated.h"

UCLASS()
class ARCHIVES_API UHideInTerrorRadiusWithStateTagQEEvaluator : public UHideInTerrorRadiusQEEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer _stateTags;

public:
	UHideInTerrorRadiusWithStateTagQEEvaluator();
};

FORCEINLINE uint32 GetTypeHash(const UHideInTerrorRadiusWithStateTagQEEvaluator) { return 0; }
