#pragma once

#include "CoreMinimal.h"
#include "OnAcquiredChanged.h"
#include "PoolableActor.h"
#include "DBDTunableRowHandle.h"
#include "EK35KillerTeleportPointState.h"
#include "ObjectStateProvider.h"
#include "BaseHusk.h"
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "K35KillerTeleportPoint.generated.h"

class AK35KillerTeleportPointInteractable;
class USphereComponent;
class UDBDOutlineComponent;
class UPrimitivesRegistererComponent;
class UK35KillerTeleportPointOutlineStrategy;
class UCapsuleComponent;
class UStaticMeshComponent;
class UClippableProviderComponent;
class UDBDNavModifierComponent;
class ADBDPlayer;
class USceneComponent;
class UK35KillerTeleportPointDangerPredictionComponent;
class UGameplayTagContainerComponent;
class ASlasherPlayer;
class UPrimitiveComponent;
class AActor;

UCLASS()
class AK35KillerTeleportPoint : public ABaseHusk, public IPoolableActor, public IObjectStateProvider
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnAcquiredChanged OnAcquiredChanged;

protected:
	UPROPERTY(EditDefaultsOnly)
	float _rotationSpeed;

	UPROPERTY(EditDefaultsOnly)
	float _minRotationDistance;

	UPROPERTY(EditDefaultsOnly)
	float _dialogRange;

	UPROPERTY(EditDefaultsOnly)
	float _decoyTouchDistance;

	UPROPERTY(EditDefaultsOnly)
	float _killerTeleportLingerTime;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _spawnTime;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AK35KillerTeleportPointInteractable> _killerTeleportPointInteractableClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UDBDOutlineComponent* _outlineComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UK35KillerTeleportPointOutlineStrategy* _outlineStrategy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UStaticMeshComponent* _targetOverlapComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UStaticMeshComponent* _playerOverlapComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UPrimitivesRegistererComponent* _primitivesRegistererComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UClippableProviderComponent* _clippableProviderComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	USphereComponent* _headSphereComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UCapsuleComponent* _bodyCapsuleComponent;

	UPROPERTY(BlueprintReadWrite, Export)
	TArray<USceneComponent*> _visionCheckingPoints;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UDBDNavModifierComponent* _navModifierComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UK35KillerTeleportPointDangerPredictionComponent* _dangerPredictionComponent;

private:
	UPROPERTY(ReplicatedUsing=OnRep_KillerTeleportPointState)
	EK35KillerTeleportPointState _killerTeleportPointState;

	UPROPERTY(ReplicatedUsing=OnRep_IsAcquiredFromPool)
	bool _isAcquiredFromPool;

	UPROPERTY(ReplicatedUsing=OnRep_KillerTeleportPointInteractable, Transient)
	AK35KillerTeleportPointInteractable* _killerTeleportPointInteractable;

	UPROPERTY(Transient)
	TSet<TWeakObjectPtr<ADBDPlayer>> _overlappingPlayers;

	UPROPERTY(Transient, Export)
	UGameplayTagContainerComponent* _objectState;

protected:
	UFUNCTION(BlueprintCallable)
	void SetHuskVisibilityChecked(const bool isVisible);

private:
	UFUNCTION()
	void OnRep_KillerTeleportPointState();

	UFUNCTION()
	void OnRep_KillerTeleportPointInteractable();

	UFUNCTION()
	void OnRep_IsAcquiredFromPool(bool oldIsAcquiredFromPool);

	UFUNCTION()
	void OnPlayerOverlapEnd(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex);

	UFUNCTION()
	void OnPlayerOverlapBegin(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnKillerTeleportPointStateChanged(const EK35KillerTeleportPointState newKillerTeleportPointState);

private:
	UFUNCTION()
	void OnKillerTeleportLingerTimeComplete();

	UFUNCTION()
	void OnKillerSet(ASlasherPlayer* killer);

	UFUNCTION()
	void OnKillerCustomizationMeshChanged();

	UFUNCTION()
	void OnIntroCompleted();

	UFUNCTION()
	void OnDecoySpawn(const FVector& location);

	UFUNCTION()
	void OnDecoyDespawn();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnCancelledDestroyInteraction(ADBDPlayer* caughtSurvivor);

public:
	UFUNCTION(BlueprintPure)
	bool IsSurvivorAbleToDestroyHusk() const;

protected:
	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerOverlapping() const;

public:
	UFUNCTION(BlueprintPure)
	bool IsKillerTeleportingToThis() const;

	UFUNCTION(BlueprintPure)
	bool IsKillerAbleToTeleportToThisPoint() const;

	UFUNCTION(BlueprintPure)
	EK35KillerTeleportPointState GetState() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnVisibilityChanged(const bool isVisible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnKillerTeleportPointStateChanged(const EK35KillerTeleportPointState newKillerTeleportPointState);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnHuskFirstTimeActivePerSpawn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnCancelledDestroyInteraction(ADBDPlayer* caughtSurvivor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAnyPlayerStartsOverlap();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAmountOfOverlappingPlayersChangedDuringOverlap();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAllPlayersStopOverlap();

private:
	UFUNCTION()
	void Authority_OnSpawnComplete();

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	AK35KillerTeleportPoint();
};

FORCEINLINE uint32 GetTypeHash(const AK35KillerTeleportPoint) { return 0; }
