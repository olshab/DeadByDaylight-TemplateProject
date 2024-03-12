#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SeancePerformerComponent.generated.h"

class USeancePerk;

UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API USeancePerformerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Replicated, Transient, Export)
	TArray<USeancePerk*> _ownedSeancePerks;

	UPROPERTY(EditDefaultsOnly)
	float _ritualInteractionMultiplierAdditive;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnStoppedInteracting(bool interrupted);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnStartedInteracting();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnInteractionCompleted();

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	USeancePerformerComponent();
};

FORCEINLINE uint32 GetTypeHash(const USeancePerformerComponent) { return 0; }
