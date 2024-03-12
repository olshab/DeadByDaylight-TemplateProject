#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "Spring2024MapComponent.generated.h"

class UStatusEffect;
class UBloodTrailSettings;

UCLASS(Abstract, meta=(BlueprintSpawnableComponent))
class USpring2024MapComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _spring2024MapStatusEffect;

	UPROPERTY(EditDefaultsOnly)
	UBloodTrailSettings* _bloodTrailSettings;

public:
	USpring2024MapComponent();
};

FORCEINLINE uint32 GetTypeHash(const USpring2024MapComponent) { return 0; }
