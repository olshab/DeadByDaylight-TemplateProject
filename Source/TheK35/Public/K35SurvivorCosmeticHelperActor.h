#pragma once

#include "CoreMinimal.h"
#include "SurvivorCosmeticHelperActor.h"
#include "GameplayTagContainer.h"
#include "GameEventData.h"
#include "K35SurvivorCosmeticHelperActor.generated.h"

UCLASS()
class AK35SurvivorCosmeticHelperActor : public ASurvivorCosmeticHelperActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPlayerLeftGame(const FGameplayTag gameplayTag, const FGameEventData& gameEventData);

	UFUNCTION()
	void OnIntroCompleted();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorLeftGame();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Comsetic_OnIntroCompleted();

public:
	AK35SurvivorCosmeticHelperActor();
};

FORCEINLINE uint32 GetTypeHash(const AK35SurvivorCosmeticHelperActor) { return 0; }
