#pragma once

#include "CoreMinimal.h"
#include "TunableStat.h"
#include "DBDTunableRowHandle.h"
#include "InteractionDefinition.h"
#include "UObject/NoExportTypes.h"
#include "K35KillerTeleportToKillerTeleportPointInteractionDefinition.generated.h"

class ACamperPlayer;
class AK35KillerTeleportPoint;
class ADBDPlayer;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UK35KillerTeleportToKillerTeleportPointInteractionDefinition : public UInteractionDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _addon20SurvivorNearDecoyOrKillerTeleportRangeDistance;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _teleportDuration;

	UPROPERTY(EditDefaultsOnly)
	FTunableStat _wakeUpTime;

	UPROPERTY(EditDefaultsOnly)
	float _killerCollisionIgnoredLingerTime;

private:
	UFUNCTION(Server, Reliable)
	void Server_SetTeleportPoint(AK35KillerTeleportPoint* killerTeleportPoint);

	UFUNCTION()
	void OnTeleportationComplete(ADBDPlayer* player);

	UFUNCTION()
	void OnKillerCollisionIgnoreLingerComplete(ADBDPlayer* player);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetTeleportPoint(AK35KillerTeleportPoint* killerTeleportPoint);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnTeleportStarted(ADBDPlayer* player, const FVector& teleportStartLocation, const FVector& teleportEndLocation, AK35KillerTeleportPoint* targetTeleportPoint);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnTeleportEnded(ADBDPlayer* player, const FVector& teleportEndLocation);

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnTeleportStart(const FVector& teleportStartLocation, const FVector& teleportEndLocation, const AK35KillerTeleportPoint* teleportPoint, const ACamperPlayer* interactingSurvivor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnTeleportEnd(const FVector& teleportEndLocation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnSurvivorScream(const ACamperPlayer* survivor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_EnableTeleportVignette(ADBDPlayer* killer);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_DisableTeleportVignette(ADBDPlayer* killer);

public:
	UK35KillerTeleportToKillerTeleportPointInteractionDefinition();
};

FORCEINLINE uint32 GetTypeHash(const UK35KillerTeleportToKillerTeleportPointInteractionDefinition) { return 0; }
