#pragma once

#include "CoreMinimal.h"
#include "KillerAnimInstance.h"
#include "GameplayTagContainer.h"
#include "GameEventData.h"
#include "K35AnimInstance.generated.h"

UCLASS(NonTransient)
class UK35AnimInstance : public UKillerAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	bool _isChargingAreaBlastTravelProjectile;

	UPROPERTY(BlueprintReadOnly)
	bool _isShootingAreaBlastTravelProjectile;

	UPROPERTY(BlueprintReadOnly)
	bool _isTeleporting;

public:
	UFUNCTION(BlueprintCallable)
	void ResetIsShootingAreaBlastTravelProjectile();

private:
	UFUNCTION()
	void OnGameEventReceived(const FGameplayTag gameplayTag, const FGameEventData& gameEventData);

public:
	UK35AnimInstance();
};

FORCEINLINE uint32 GetTypeHash(const UK35AnimInstance) { return 0; }
