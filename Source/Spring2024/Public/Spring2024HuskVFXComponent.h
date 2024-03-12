#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Spring2024HuskVFXComponent.generated.h"

class ABaseHusk;

UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class USpring2024HuskVFXComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	TWeakObjectPtr<ABaseHusk> _owningHusk;

private:
	UFUNCTION()
	void RegisterVFXListeners();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_SetChargeVisible(int32 chargeAmount, bool isVisible) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_SetBloodBoostVisible(bool visible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnHuskVFXComponentReady();

public:
	USpring2024HuskVFXComponent();
};

FORCEINLINE uint32 GetTypeHash(const USpring2024HuskVFXComponent) { return 0; }
