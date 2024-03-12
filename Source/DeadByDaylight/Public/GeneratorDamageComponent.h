#pragma once

#include "CoreMinimal.h"
#include "DBDTunableRowHandle.h"
#include "Components/ActorComponent.h"
#include "DamageData.h"
#include "GeneratorDamageComponent.generated.h"

class ADBDPlayer;

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API UGeneratorDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCosmeticMakeSurvivorScreamDelegate, const ADBDPlayer*, screamingSurvivor);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCosmeticGeneratorDamagedDelegate, bool, intense);

protected:
	UPROPERTY(BlueprintAssignable)
	FCosmeticGeneratorDamagedDelegate Cosmetic_OnGeneratorDamaged;

	UPROPERTY(BlueprintAssignable)
	FCosmeticMakeSurvivorScreamDelegate Cosmetic_MakeSurvivorScream;

private:
	UPROPERTY(ReplicatedUsing=OnRep_DamageData, Transient)
	FDamageData _damageData;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _gradualRegressionPercentPerDamage;

private:
	UFUNCTION()
	void OnRep_DamageData();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_DamageEffects(const float immediateRegressionPercent, const TArray<ADBDPlayer*>& repairers, const bool playLoudNoise);

public:
	UFUNCTION(BlueprintPure)
	bool IsRegressing() const;

	UFUNCTION(BlueprintPure)
	bool IsIntenseDamage() const;

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UGeneratorDamageComponent();
};

FORCEINLINE uint32 GetTypeHash(const UGeneratorDamageComponent) { return 0; }
