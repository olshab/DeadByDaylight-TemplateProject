#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameplayTagContainer.h"
#include "GameEventData.h"
#include "K35KillerTeleportPointAnimInstance.generated.h"

UCLASS(NonTransient)
class UK35KillerTeleportPointAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	bool _isVisible;

	UPROPERTY(BlueprintReadOnly)
	bool _isOnCooldown;

	UPROPERTY(BlueprintReadOnly)
	bool _isBeingDestroyedBySurvivor;

	UPROPERTY(BlueprintReadOnly)
	bool _isKillerTeleportingToOwner;

public:
	UFUNCTION(BlueprintCallable)
	void ResetIsKillerTeleportingToOwner();

private:
	UFUNCTION()
	void OnGameEventReceived(const FGameplayTag gameplayTag, const FGameEventData& gameEventData);

public:
	UK35KillerTeleportPointAnimInstance();
};

FORCEINLINE uint32 GetTypeHash(const UK35KillerTeleportPointAnimInstance) { return 0; }
