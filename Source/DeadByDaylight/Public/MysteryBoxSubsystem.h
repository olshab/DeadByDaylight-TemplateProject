#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MysteryBoxSubsystem.generated.h"

UCLASS()
class DEADBYDAYLIGHT_API UMysteryBoxSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnTimeTravel(bool success, const FString& date);

	UFUNCTION()
	void OnNextClaimTimeTimerElapsed(const FString& campaign);

	UFUNCTION()
	void OnGameInstanceInitialized();

public:
	UMysteryBoxSubsystem();
};

FORCEINLINE uint32 GetTypeHash(const UMysteryBoxSubsystem) { return 0; }
