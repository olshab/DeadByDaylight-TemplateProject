#pragma once

#include "CoreMinimal.h"
#include "Perk.h"
#include "Templates/SubclassOf.h"
#include "Eruption.generated.h"

class AGenerator;
class UStatusEffect;

UCLASS(meta=(BlueprintSpawnableComponent))
class UEruption : public UPerk
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<AGenerator*> _server_affectedGenerators;

	UPROPERTY(Replicated)
	bool _isPerkEnabled;

	UPROPERTY(EditDefaultsOnly)
	float _generatorRegressPercentage;

	UPROPERTY(EditDefaultsOnly)
	float _survivorImposedStatusEffectDuration;

	UPROPERTY(EditDefaultsOnly)
	float _perkCooldownDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	float _screamRevealLocationDuration;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _survivorEffectClass;

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_RemoveHighlights(const TArray<AGenerator*>& highlightedGenerators);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_HighlightGenerator(AGenerator* generator);

public:
	UFUNCTION(BlueprintPure)
	float GetSurvivorImposedStatusEffectDurationAtLevel() const;

protected:
	UFUNCTION(BlueprintPure)
	float GetScreamRevealLocationDuration() const;

public:
	UFUNCTION(BlueprintPure)
	float GetGeneratorRegressPercentageAtLevel() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnGeneratorHighlightStart(AGenerator* highlightedGenerator);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnGeneratorHighlightEnd(AGenerator* highlightedGenerator);

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UEruption();
};

FORCEINLINE uint32 GetTypeHash(const UEruption) { return 0; }
