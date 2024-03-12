#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "Spring2024EventCheatComponent.generated.h"

class ABloodZone;
class ABloodReceptacle;

UCLASS(meta=(BlueprintSpawnableComponent))
class USpring2024EventCheatComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABloodZone> _bloodZoneClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABloodReceptacle> _bloodReceptacleClass;

public:
	UFUNCTION(Exec)
	void DBD_Spring2024UnprotectAllBloodZone() const;

	UFUNCTION(Exec)
	void DBD_Spring2024ShowBloodZoneInfluence() const;

	UFUNCTION(Exec)
	void DBD_Spring2024ForceSpawnAllBloodZone() const;

	UFUNCTION(Exec)
	void DBD_Spring2024ForceSpawnAllBloodReceptacle() const;

	UFUNCTION(Exec)
	void DBD_Spring2024DeactivateAllBloodZone() const;

	UFUNCTION(Exec)
	void DBD_Spring2024ActivateAllBloodZone(const FString& localPlayerId) const;

public:
	USpring2024EventCheatComponent();
};

FORCEINLINE uint32 GetTypeHash(const USpring2024EventCheatComponent) { return 0; }
