#pragma once

#include "CoreMinimal.h"
#include "DBDTunableRowHandle.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "Spring2024EventComponent.generated.h"

class UStatusEffect;
class ABloodZone;
class USpring2024EventCheatComponent;

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class USpring2024EventComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _survivorEventStatusEffect;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _killerEventStatusEffect;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _offeringStatusEffect;

	UPROPERTY(EditDefaultsOnly)
	TArray<FDBDTunableRowHandle> _dreamLevelBonusValue;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABloodZone> _bloodZoneClassToSpawn;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneSpawnDistance;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _bloodZoneHeight;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<USpring2024EventCheatComponent> _eventCheatComponentClass;

private:
	UFUNCTION()
	void Authority_OnLevelReadyToPlay();

public:
	USpring2024EventComponent();
};

FORCEINLINE uint32 GetTypeHash(const USpring2024EventComponent) { return 0; }
