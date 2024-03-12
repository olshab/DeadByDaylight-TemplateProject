#pragma once

#include "CoreMinimal.h"
#include "Collectable.h"
#include "Templates/SubclassOf.h"
#include "TagStateBool.h"
#include "K35Power.generated.h"

class UInteractionAttacherComponent;
class AK35KillerTeleportPointTargetingIndicator;
class AK35AreaBlast;
class UStatusEffect;
class AK35Decoy;
class ACamperPlayer;

UCLASS()
class AK35Power : public ACollectable
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMoriStateChanged);

protected:
	UPROPERTY(BlueprintAssignable)
	FOnMoriStateChanged OnMoriBegin;

	UPROPERTY(BlueprintAssignable)
	FOnMoriStateChanged OnMoriEnd;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AK35AreaBlast> _areaBlastClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AK35Decoy> _decoyClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AK35KillerTeleportPointTargetingIndicator> _teleportPointTargetingIndicatorClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _extendedDestructionTimeWhenInfectedStatusEffect;

	UPROPERTY(EditDefaultsOnly, meta=(BindWidgetOptional))
	UInteractionAttacherComponent* _interactionAttacherComponent;

	UPROPERTY(EditDefaultsOnly)
	float _cosmeticIdleTimerBuffer;

	UPROPERTY(EditDefaultsOnly)
	float _minKillerCosmeticIdleTime;

	UPROPERTY(EditDefaultsOnly)
	float _maxKillerCosmeticIdleTime;

	UPROPERTY(EditDefaultsOnly)
	float _minKillerTeleportPointCosmeticIdleTime;

	UPROPERTY(EditDefaultsOnly)
	float _maxKillerTeleportPointCosmeticIdleTime;

private:
	UPROPERTY(Replicated, Transient)
	AK35AreaBlast* _areaBlast;

	UPROPERTY(Replicated, Transient)
	AK35Decoy* _decoy;

	UPROPERTY(Transient)
	AK35KillerTeleportPointTargetingIndicator* _teleportPointTargetingIndicator;

	UPROPERTY(Transient)
	FTagStateBool _isKillerInMori;

private:
	UFUNCTION()
	void OnSurvivorAdded(ACamperPlayer* survivor) const;

	UFUNCTION()
	void OnKillerTeleportPointCosmeticIdleTimeComplete();

	UFUNCTION()
	void OnKillerCosmeticIdleTimeComplete();

	UFUNCTION()
	void OnIntroCompleted();

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	AK35Power();
};

FORCEINLINE uint32 GetTypeHash(const AK35Power) { return 0; }
