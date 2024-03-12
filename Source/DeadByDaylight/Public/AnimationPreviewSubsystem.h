#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AnimationPreviewSubsystem.generated.h"

class UAnimationPreview;

UCLASS(BlueprintType)
class DEADBYDAYLIGHT_API UAnimationPreviewSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UAnimationPreview* _activePreview;

private:
	UFUNCTION()
	void OnAnimationPreviewEnd(UAnimationPreview* preview, bool completedSuccessfully);

public:
	UFUNCTION(BlueprintPure)
	bool IsPreviewingAnimation() const;

public:
	UAnimationPreviewSubsystem();
};

FORCEINLINE uint32 GetTypeHash(const UAnimationPreviewSubsystem) { return 0; }
