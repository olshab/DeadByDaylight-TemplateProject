#pragma once

#include "CoreMinimal.h"
#include "GameplayMutator.h"
#include "OnLevelReadyToPlayBaseMutator.generated.h"

UCLASS(Blueprintable, Abstract, meta=(BlueprintSpawnableComponent))
class UOnLevelReadyToPlayBaseMutator : public UGameplayMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	void OnLevelReadyToPlay();

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnInitializedMutator(float customParam);

public:
	UOnLevelReadyToPlayBaseMutator();
};

FORCEINLINE uint32 GetTypeHash(const UOnLevelReadyToPlayBaseMutator) { return 0; }
