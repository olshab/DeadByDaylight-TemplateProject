#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Templates/SubclassOf.h"
#include "SeanceRitualSpot.generated.h"

class AActor;
class UStatusEffect;
class ADBDPlayer;
class ACamperPlayer;
class UChargeableComponent;

UCLASS()
class DEADBYDAYLIGHT_API ASeanceRitualSpot : public AInteractable
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidgetOptional))
	UChargeableComponent* _ritualChargeable;

	UPROPERTY(EditDefaultsOnly)
	float _secondsToCharge;

	UPROPERTY(EditDefaultsOnly)
	float _dechargeRate;

	UPROPERTY(Replicated, Transient)
	ACamperPlayer* _ritualOriginator;

	UPROPERTY(ReplicatedUsing=OnRep_SurvivorsPerformingRitual, Transient)
	TArray<ACamperPlayer*> _survivorsPerformingRitual;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _revealAuraEffectClass;

	UPROPERTY(Replicated)
	bool _ritualUseable;

	UPROPERTY(Transient)
	TMap<ADBDPlayer*, float> _authority_progressAmountsCumulative;

protected:
	UFUNCTION()
	void OnRep_SurvivorsPerformingRitual();

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool OnFinishedRitual();

protected:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnSeanceCompleted(ACamperPlayer* originator);

public:
	UFUNCTION(BlueprintPure)
	TArray<ACamperPlayer*> GetRitualPerformers() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_SurvivorsPerformingRitualUpdated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnStoppedInteracting(bool interrupted);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnStartedInteracting(ADBDPlayer* interactingPlayer, bool isOriginator);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnInteractionUpdate(const ADBDPlayer* interactingPlayer, const float chargePercent);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnInteractionCompleted();

public:
	UFUNCTION()
	void Authority_OnPerformRitualChargePercentChanged(UChargeableComponent* chargeableComponent, float percentCompletionChange, float totalPercentComplete);

	UFUNCTION()
	void Authority_OnChargeApplied(float individualChargeAmount, float totalChargeAmount, AActor* chargeInstigator, bool wasCoop, float deltaTime);

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	ASeanceRitualSpot();
};

FORCEINLINE uint32 GetTypeHash(const ASeanceRitualSpot) { return 0; }
