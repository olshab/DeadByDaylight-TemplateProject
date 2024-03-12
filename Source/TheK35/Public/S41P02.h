#pragma once

#include "CoreMinimal.h"
#include "Perk.h"
#include "Templates/SubclassOf.h"
#include "S41P02.generated.h"

class UInteractionDefinition;
class UStatusEffect;
class UInteractionAttacherComponent;

UCLASS(meta=(BlueprintSpawnableComponent))
class US41P02 : public UPerk
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _timedRevealKillerAuraEffectClass;

	UPROPERTY(EditDefaultsOnly)
	float _auraDuration;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _selfHealNoMedkitSpeedPenaltyEffectClass;

	UPROPERTY(EditDefaultsOnly)
	float _selfHealSpeedPenalty;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInteractionDefinition> _s41p02HealInteraction;

	UPROPERTY(ReplicatedUsing=OnRep_InteractionAttacherComponent, Transient, Export)
	UInteractionAttacherComponent* _interactionAttacherComponent;

private:
	UFUNCTION()
	void OnRep_InteractionAttacherComponent();

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	US41P02();
};

FORCEINLINE uint32 GetTypeHash(const US41P02) { return 0; }
