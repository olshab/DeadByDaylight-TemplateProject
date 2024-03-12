#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameplayTagContainer.h"
#include "GameEventData.h"
#include "K35NeckWormAnimInstance.generated.h"

class ASlasherPlayer;

UCLASS(NonTransient)
class UK35NeckWormAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	bool _isChargingAreaBlastTravelProjectile;

	UPROPERTY(BlueprintReadOnly)
	bool _isShootingAreaBlastTravelProjectile;

public:
	UFUNCTION(BlueprintCallable)
	void ResetIsShootingAreaBlastTravelProjectile();

private:
	UFUNCTION()
	void OnKillerSet(ASlasherPlayer* killer);

	UFUNCTION()
	void OnGameEventReceived(const FGameplayTag gameplayTag, const FGameEventData& gameEventData);

public:
	UK35NeckWormAnimInstance();
};

FORCEINLINE uint32 GetTypeHash(const UK35NeckWormAnimInstance) { return 0; }
