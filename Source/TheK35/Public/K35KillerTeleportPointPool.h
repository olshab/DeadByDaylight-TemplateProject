#pragma once

#include "CoreMinimal.h"
#include "TunableStat.h"
#include "AuthoritativeActorPoolComponent.h"
#include "GameplayTagContainer.h"
#include "GameEventData.h"
#include "K35KillerTeleportPointPool.generated.h"

class AActor;
class ACamperPlayer;
class ASlasherPlayer;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UK35KillerTeleportPointPool : public UAuthoritativeActorPoolComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	FTunableStat _maxKillerTeleportPoints;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _secondsCooldown;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _visibleAuraDistanceSurvivor;

private:
	UFUNCTION()
	void OnKillerTeleportPointSpawned();

	UFUNCTION()
	void OnKillerTeleportPointCreated(AActor* actor);

	UFUNCTION()
	void OnKillerTeleportPointAcquiredChanged(const bool isAcquired);

	UFUNCTION()
	void OnKillerSet(ASlasherPlayer* killer);

	UFUNCTION()
	void OnIntroCompleted();

	UFUNCTION()
	void Authority_OnSurvivorDamaged(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void Authority_OnKillerTeleportCooldownComplete();

	UFUNCTION()
	void Authority_OnInRangeChanged(const bool isInRange, ACamperPlayer* survivor);

public:
	UK35KillerTeleportPointPool();
};

FORCEINLINE uint32 GetTypeHash(const UK35KillerTeleportPointPool) { return 0; }
