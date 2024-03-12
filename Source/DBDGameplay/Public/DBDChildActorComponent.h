#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"
#include "DBDChildActorComponent.generated.h"

class AActor;

UCLASS(meta=(BlueprintSpawnableComponent))
class DBDGAMEPLAY_API UDBDChildActorComponent : public USceneComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> _childActorToSpawn;

	UPROPERTY(EditDefaultsOnly)
	FName _socketNameToAttach;

	UPROPERTY(EditDefaultsOnly)
	EAttachmentRule _attachmentLocationRule;

	UPROPERTY(EditDefaultsOnly)
	EAttachmentRule _attachmentRotationRule;

	UPROPERTY(EditDefaultsOnly)
	EAttachmentRule _attachmentScaleRule;

	UPROPERTY(EditDefaultsOnly)
	bool _weldSimulatedBodies;

	UPROPERTY(EditDefaultsOnly)
	FTransform _childActorTransformOnSpawn;

private:
	UPROPERTY()
	AActor* _childActor;

public:
	UDBDChildActorComponent();
};

FORCEINLINE uint32 GetTypeHash(const UDBDChildActorComponent) { return 0; }
