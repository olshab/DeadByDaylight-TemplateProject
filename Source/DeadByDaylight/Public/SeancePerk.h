#pragma once

#include "CoreMinimal.h"
#include "Perk.h"
#include "Templates/SubclassOf.h"
#include "EManifestationTarget.h"
#include "SeancePerk.generated.h"

class USeancePerformerComponent;
class UStatusEffect;

UCLASS(meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API USeancePerk : public UPerk
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<USeancePerformerComponent> _seancePerformerComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UStatusEffect> _brokenEffect;

	UPROPERTY(EditAnywhere)
	EManifestationTarget _effectTarget;

	UPROPERTY(Replicated)
	bool _isSeancePerformed;

	UPROPERTY(EditAnywhere)
	bool _destructivePerk;

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	USeancePerk();
};

FORCEINLINE uint32 GetTypeHash(const USeancePerk) { return 0; }
