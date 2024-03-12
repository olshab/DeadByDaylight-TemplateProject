#pragma once

#include "CoreMinimal.h"
#include "TunableStat.h"
#include "ObjectStateProvider.h"
#include "BaseHusk.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "K35Decoy.generated.h"

class UPrimitivesRegistererComponent;
class UCapsuleComponent;
class UStaticMeshComponent;
class UGameplayTagContainerComponent;
class UClippableProviderComponent;
class USphereComponent;
class ADBDPlayer;
class ASlasherPlayer;
class UPrimitiveComponent;
class AActor;

UCLASS()
class AK35Decoy : public ABaseHusk, public IObjectStateProvider
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	float _killerOverlapIgnoreOnSpawnDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UStaticMeshComponent* _playerOverlapComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UPrimitivesRegistererComponent* _primitivesRegistererComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UClippableProviderComponent* _clippableProviderComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	USphereComponent* _headSphereComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName _bodySocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName _headSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidgetOptional))
	UCapsuleComponent* _bodyCapsuleComponent;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _selfDestroyTime;

	UPROPERTY(BlueprintReadOnly)
	bool _isTerrorRadiusAndRedStainActive;

private:
	UPROPERTY(Transient)
	TSet<TWeakObjectPtr<ADBDPlayer>> _overlappingPlayers;

	UPROPERTY(Transient, Export)
	UGameplayTagContainerComponent* _objectState;

protected:
	UFUNCTION(BlueprintCallable)
	void SetHuskVisibilityChecked(const bool isVisible);

private:
	UFUNCTION()
	void OnPlayerOverlapEnd(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex);

	UFUNCTION()
	void OnPlayerOverlapBegin(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnKillerSet(ASlasherPlayer* killer);

	UFUNCTION()
	void OnKillerCustomizationMeshChanged();

	UFUNCTION()
	void OnIntroCompleted();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_Spawn(const FVector spawnLocation);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SelfDestruct();

protected:
	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerOverlapping() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnVisibilityChanged(const bool isVisible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnIntroCompleted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAnyPlayerStartsOverlap();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAmountOfOverlappingPlayersChangedDuringOverlap();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAllPlayersStopOverlap();

private:
	UFUNCTION()
	void Authority_OnSelfDestructTimerComplete();

public:
	AK35Decoy();
};

FORCEINLINE uint32 GetTypeHash(const AK35Decoy) { return 0; }
