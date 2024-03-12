#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActorSpawner.h"
#include "EventSpawnablePositionDropdown.h"
#include "DataTableDropdown.h"
#include "EventSpawner.generated.h"

class UBoxComponent;

UCLASS(meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API UEventSpawner : public UActorSpawner
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FEventSpawnablePositionDropdown EventSpawnablePosition;

	UPROPERTY(EditAnywhere)
	FDataTableDropdown EventSpawnableShapePreset;

	UPROPERTY(EditAnywhere)
	FVector MinBoundOverride;

	UPROPERTY(EditAnywhere)
	FVector MaxBoundOverride;

private:
	UPROPERTY(Transient, Export)
	UBoxComponent* _minBoundBox;

	UPROPERTY(Transient, Export)
	UBoxComponent* _maxBoundBox;

public:
	UEventSpawner();
};

FORCEINLINE uint32 GetTypeHash(const UEventSpawner) { return 0; }
