#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DBDBaseActor.generated.h"

class USceneComponent;

UCLASS(Abstract)
class ADBDBaseActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(Export)
	USceneComponent* _rootComponent;

public:
	ADBDBaseActor();
};

FORCEINLINE uint32 GetTypeHash(const ADBDBaseActor) { return 0; }
