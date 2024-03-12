#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "TagStateBool.h"
#include "GameEventData.h"
#include "BloodZoneTrackerPlayerComponent.generated.h"

class ABloodZone;

UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class UBloodZoneTrackerPlayerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<ABloodZone*> _authority_bloodZonesInRange;

	UPROPERTY(ReplicatedUsing=OnRep_isInBloodZone)
	FTagStateBool _isInBloodZone;

private:
	UFUNCTION()
	void OnRep_IsInBloodZone();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OutsideBloodZone();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnKillerLocallyObservedChanged(bool locallyObserved);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_InsideBloodZone();

private:
	UFUNCTION()
	void Authority_OnPlayerExitBloodZone(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void Authority_OnPlayerEnterBloodZone(FGameplayTag gameEventType, const FGameEventData& gameEventData);

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UBloodZoneTrackerPlayerComponent();
};

FORCEINLINE uint32 GetTypeHash(const UBloodZoneTrackerPlayerComponent) { return 0; }
