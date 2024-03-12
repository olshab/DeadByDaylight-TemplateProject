#pragma once

#include "CoreMinimal.h"
#include "EBloodZoneState.h"
#include "Interactable.h"
#include "DBDTunableRowHandle.h"
#include "BloodZone.generated.h"

class UDBDOutlineComponent;
class UChargeableComponent;
class UInteractor;
class UStaticMeshComponent;
class UBloodZoneDeactivationInteraction;
class ADBDPlayer;
class UPrimitiveComponent;
class UBloodZoneOutlineUpdateStrategy;
class UBloodZoneActivationInteraction;

UCLASS()
class ABloodZone : public AInteractable
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, meta=(BindWidgetOptional))
	UStaticMeshComponent* _bloodZoneStaticMesh;

	UPROPERTY(EditDefaultsOnly, NoClear, meta=(BindWidgetOptional))
	UDBDOutlineComponent* _outlineComponent;

	UPROPERTY(EditDefaultsOnly, NoClear, meta=(BindWidgetOptional))
	UBloodZoneOutlineUpdateStrategy* _outlineUpdateStrategy;

private:
	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UPrimitiveComponent* _bloodZoneInteractionZone;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UInteractor* _bloodZoneInteractor;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UBloodZoneActivationInteraction* _bloodZoneActivationInteractionSurvivor;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UBloodZoneActivationInteraction* _bloodZoneActivationInteractionKiller;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UChargeableComponent* _bloodZoneActivationChargeableSurvivor;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UChargeableComponent* _bloodZoneActivationChargeableKiller;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UBloodZoneDeactivationInteraction* _bloodZoneDeactivationInteractionSurvivor;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UBloodZoneDeactivationInteraction* _bloodZoneDeactivationInteractionKiller;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UChargeableComponent* _bloodZoneDeactivationChargeableSurvivor;

	UPROPERTY(VisibleAnywhere, NoClear, Export)
	UChargeableComponent* _bloodZoneDeactivationChargeableKiller;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneActivationInteractionSecondsToChargeSurvivor;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneActivationInteractionSecondsToChargeKiller;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneDeactivationInteractionSecondsToChargeSurvivor;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneDeactivationInteractionSecondsToChargeKiller;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneRadius;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneLowerHeightDifference;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneUpperHeightDifference;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _killerProtectedTime;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _survivorProtectedTime;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _outlineRevealDistance;

	UPROPERTY(ReplicatedUsing=OnRep_State)
	EBloodZoneState _state;

private:
	UFUNCTION()
	void OnSurvivorDeactivationInteractionEntered(ADBDPlayer* player);

	UFUNCTION()
	void OnSurvivorActivationInteractionEntered(ADBDPlayer* player);

	UFUNCTION()
	void OnRep_State(EBloodZoneState oldState);

	UFUNCTION()
	void OnKillerDeactivationInteractionEntered(ADBDPlayer* player);

	UFUNCTION()
	void OnKillerActivationInteractionEntered(ADBDPlayer* player);

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnVulnerable();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnDeactivated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_IsBeingRemovedEnd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_IsBeingRemovedBegin(const ADBDPlayer* interactingPlayer);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_IsBeingActivatedEnd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_IsBeingActivatedBegin(float chargeTime);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_InitializeBloodZone();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_ActivatedBySurvivor();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_ActivatedByKiller();

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	ABloodZone();
};

FORCEINLINE uint32 GetTypeHash(const ABloodZone) { return 0; }
