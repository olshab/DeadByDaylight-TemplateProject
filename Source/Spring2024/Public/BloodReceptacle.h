#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DBDTunableRowHandle.h"
#include "GameplayTagContainer.h"
#include "Engine/EngineTypes.h"
#include "BloodReceptacle.generated.h"

class UStaticMeshComponent;
class UBloodReceptacleOutlineUpdateStrategy;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(Abstract)
class ABloodReceptacle : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, NoClear, meta=(BindWidgetOptional))
	UStaticMeshComponent* _bloodReceptacleStaticMesh;

private:
	UPROPERTY(VisibleAnywhere, NoClear, Export)
	USphereComponent* _bloodReceptacleCollectionZone;

	UPROPERTY(EditAnywhere, NoClear, Export)
	UBloodReceptacleOutlineUpdateStrategy* _outlineUpdateStrategy;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer _preventingCollectionStateTags;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _collectionRadius;

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnChargeCollected();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnChargeCollected();

private:
	UFUNCTION()
	void Authority_OnEnterCollectionZone(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

public:
	ABloodReceptacle();
};

FORCEINLINE uint32 GetTypeHash(const ABloodReceptacle) { return 0; }
