#pragma once

#include "CoreMinimal.h"
#include "DBDTunableRowHandle.h"
#include "Components/ActorComponent.h"
#include "K35SurvivorLookStatus.h"
#include "K35SightManager.generated.h"

class UCharacterSightComponent;
class ACharacter;

UCLASS(meta=(BlueprintSpawnableComponent))
class UK35SightManager : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _maximumSightDistance;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _sightingDelay;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _discerningDelay;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _undiscerningDelay;

private:
	UPROPERTY(Replicated)
	TArray<FK35SurvivorLookStatus> _survivorLookStatus;

private:
	UFUNCTION()
	void OnIntroCompleted();

	UFUNCTION()
	void Authority_OnCharacterSightChanged(ACharacter* sightedCharacter, UCharacterSightComponent* sightComponent);

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UK35SightManager();
};

FORCEINLINE uint32 GetTypeHash(const UK35SightManager) { return 0; }
