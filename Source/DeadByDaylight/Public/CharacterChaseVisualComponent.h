#pragma once

#include "CoreMinimal.h"
#include "ActorComponentChaseStartSignature.h"
#include "Components/ActorComponent.h"
#include "ActorComponentChaseEndSignature.h"
#include "UObject/NoExportTypes.h"
#include "CharacterChaseVisualComponent.generated.h"

class UMaterialHelperUnaffectedStaticMeshComponent;

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API UCharacterChaseVisualComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FActorComponentChaseStartSignature OnChaseStartEvent;

	UPROPERTY(BlueprintAssignable)
	FActorComponentChaseEndSignature OnChaseEndEvent;

private:
	UPROPERTY(Transient, Export)
	UMaterialHelperUnaffectedStaticMeshComponent* _vignetteMeshComp;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	FVector _relativeLocation;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	FVector _relativeScale;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	FRotator _relativeRotation;

	UPROPERTY(EditDefaultsOnly)
	float _fovModifyFactor;

public:
	UFUNCTION()
	void OnAllChaseEnd();

public:
	UCharacterChaseVisualComponent();
};

FORCEINLINE uint32 GetTypeHash(const UCharacterChaseVisualComponent) { return 0; }
