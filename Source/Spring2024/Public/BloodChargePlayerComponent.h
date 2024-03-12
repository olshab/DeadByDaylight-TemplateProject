#pragma once

#include "CoreMinimal.h"
#include "EventObjectItemWidgetInterface.h"
#include "DBDTunableRowHandle.h"
#include "Components/ActorComponent.h"
#include "BloodChargePlayerComponent.generated.h"

UCLASS(Blueprintable, Abstract, meta=(BlueprintSpawnableComponent))
class UBloodChargePlayerComponent : public UActorComponent, public IEventObjectItemWidgetInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodChargeLimitSurvivor;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodChargeLimitKiller;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodChargeStartAmountKiller;

	UPROPERTY(ReplicatedUsing=OnRep_BloodChargeAmount)
	int32 _bloodChargeAmount;

	UPROPERTY(Replicated)
	bool _lastChargeChangeFromStealing;

private:
	UFUNCTION()
	void OnRep_BloodChargeAmount(int32 oldAmount);

	UFUNCTION()
	void OnLevelReadyToPlay();

	UFUNCTION()
	void OnHudPresenterReady() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorLoseCharge(int32 chargeCount, bool stolen);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorGainCharge(int32 chargeCount, bool stolen);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnKillerLoseCharge(int32 chargeCount, bool stolen);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnKillerGainCharge(int32 chargeCount, bool stolen);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_InitializeComponent();

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UBloodChargePlayerComponent();
};

FORCEINLINE uint32 GetTypeHash(const UBloodChargePlayerComponent) { return 0; }
