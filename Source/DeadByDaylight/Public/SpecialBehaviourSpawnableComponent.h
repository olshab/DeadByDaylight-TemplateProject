#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "SpecialBehaviourSpawnableComponent.generated.h"

class UActorComponent;
class ADBDPlayer;

USTRUCT(BlueprintType)
struct FSpecialBehaviourSpawnableComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UActorComponent> Component;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool ShouldSpawnOnSurvivor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool ShouldSpawnOnKiller;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool ShouldSpawnOnGameState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSoftClassPtr<ADBDPlayer>> ShouldSpawnOnPlayerClasses;

public:
	DEADBYDAYLIGHT_API FSpecialBehaviourSpawnableComponent();
};

FORCEINLINE uint32 GetTypeHash(const FSpecialBehaviourSpawnableComponent) { return 0; }
