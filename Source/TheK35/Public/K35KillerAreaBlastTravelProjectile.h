#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "KillerProjectile.h"
#include "TunableStat.h"
#include "DBDTunableRowHandle.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"
#include "K35KillerAreaBlastTravelProjectile.generated.h"

class UKillerProjectileDodgeComponent;
class UPrimitiveComponent;
class USphereComponent;
class ASlasherPlayer;
class UStatusEffect;
class AActor;
class ACamperPlayer;

UCLASS()
class AK35KillerAreaBlastTravelProjectile : public AKillerProjectile
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	USphereComponent* _environmentCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	USphereComponent* _playerCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UKillerProjectileDodgeComponent* _killerProjectileDodge;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _projectileTimeoutTime;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _maxAllowedBounces;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _bounciness;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _friction;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _hinderedOnPassThroughLifetime;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _hinderedOnPassThroughStatusEffectClass;

	UPROPERTY(BlueprintReadOnly)
	bool _isProjectileActive;

private:
	UFUNCTION()
	void OnSurvivorHitDetected(UPrimitiveComponent* component, const FHitResult& hit);

	UFUNCTION()
	void OnKillerSet(ASlasherPlayer* killer);

	UFUNCTION()
	void OnIntroCompleted();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnProjectileReachedEnd(const FVector endLocation);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_BreakWallOrDownedPallet(AActor* wallOrPallet);

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnProjectileHitSurvivor(ACamperPlayer* survivor, const float hinderedLifetime);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnProjectileHitEnvironment(const FVector& impactLocation, const FVector& impactNormal, const TEnumAsByte<EPhysicalSurface>& surfaceType);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnLaunch();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnEndReached();

private:
	UFUNCTION()
	void Authority_OnProjectileTimeout();

	UFUNCTION()
	void Authority_OnEnvironmentCollisionComponentOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool isFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void Authority_OnEnvironmentCollisionComponentHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hit);

public:
	AK35KillerAreaBlastTravelProjectile();
};

FORCEINLINE uint32 GetTypeHash(const AK35KillerAreaBlastTravelProjectile) { return 0; }
