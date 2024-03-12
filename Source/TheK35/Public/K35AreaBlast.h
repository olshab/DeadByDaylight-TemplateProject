#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DBDTunableRowHandle.h"
#include "ECamperDamageState.h"
#include "EK35AreaBlastState.h"
#include "UObject/NoExportTypes.h"
#include "K35AreaBlast.generated.h"

class UCurveFloat;
class USceneComponent;
class USphereComponent;
class ACamperPlayer;

UCLASS()
class AK35AreaBlast : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	TMap<EK35AreaBlastState, FDBDTunableRowHandle> _stateDurationMap;

	UPROPERTY(EditDefaultsOnly)
	TMap<EK35AreaBlastState, EK35AreaBlastState> _nextStateMap;

	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* _growCurve;

	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* _shrinkCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	USphereComponent* _playerCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	USceneComponent* _offsetComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FDBDTunableRowHandle _minScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FDBDTunableRowHandle _maxScale;

private:
	UPROPERTY()
	TArray<ACamperPlayer*> _affectedSurvivors;

private:
	UFUNCTION()
	void OnIntroCompleted();

protected:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SurvivorDamagedByAreaBlast(ACamperPlayer* survivor, ECamperDamageState targetHealthState);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SurvivorAfflictedWithKillerEffectByAreaBlast(ACamperPlayer* survivor, ECamperDamageState currentHealthState);

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_Spawn(const FVector& spawnLocation);

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_ToggleAreaBlastDebugSphere();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorDamagedByAreaBlast(ACamperPlayer* survivor, ECamperDamageState targetHealthState, bool isAnySurvivorAlreadyHit);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorAfflictedWithKillerEffectByAreaBlast(ACamperPlayer* survivor, ECamperDamageState currentHealthState);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnStateChanged(EK35AreaBlastState newState);

public:
	AK35AreaBlast();
};

FORCEINLINE uint32 GetTypeHash(const AK35AreaBlast) { return 0; }
