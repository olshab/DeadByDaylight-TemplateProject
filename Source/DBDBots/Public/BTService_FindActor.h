#pragma once

#include "CoreMinimal.h"
#include "BTService_FindGoalObject.h"
#include "UObject/NoExportTypes.h"
#include "BTService_FindActor.generated.h"

UCLASS(Abstract)
class DBDBOTS_API UBTService_FindActor : public UBTService_FindGoalObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly)
	FVector ActorLocationOffset;

public:
	UBTService_FindActor();
};

FORCEINLINE uint32 GetTypeHash(const UBTService_FindActor) { return 0; }
