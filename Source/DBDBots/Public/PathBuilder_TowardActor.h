#pragma once

#include "CoreMinimal.h"
#include "PathBuilder.h"
#include "Templates/SubclassOf.h"
#include "PathBuilder_TowardActor.generated.h"

class UNavigationQueryFilter;
class AActor;

UCLASS(EditInlineNew)
class DBDBOTS_API UPathBuilder_TowardActor : public UPathBuilder
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> FindClass;

	UPROPERTY(EditDefaultsOnly)
	bool UseClosestEscapePointIfAvailable;

	UPROPERTY(EditDefaultsOnly)
	float OpenDoorOffset;

	UPROPERTY(EditDefaultsOnly)
	float MinimumDistance;

	UPROPERTY(EditDefaultsOnly)
	float MaximumDistance;

	UPROPERTY(EditDefaultsOnly)
	bool SearchForClosestActor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UNavigationQueryFilter> FilterClass;

public:
	UPathBuilder_TowardActor();
};

FORCEINLINE uint32 GetTypeHash(const UPathBuilder_TowardActor) { return 0; }
