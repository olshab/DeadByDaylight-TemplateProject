#pragma once

#include "CoreMinimal.h"
#include "DialogHandlerConditionContainer.h"
#include "DialogClipSettings.generated.h"

class UAkAudioEvent;

USTRUCT()
struct FDialogClipSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	UAkAudioEvent* Clip;

	UPROPERTY(EditDefaultsOnly)
	FDialogHandlerConditionContainer ConditionContainer;

	UPROPERTY(EditDefaultsOnly)
	int32 Priority;

	UPROPERTY(EditDefaultsOnly)
	int32 Weight;

	UPROPERTY(EditDefaultsOnly)
	bool IsOnlyPlayingOnce;

	UPROPERTY(EditDefaultsOnly)
	bool HasSubtitles;

public:
	DEADBYDAYLIGHT_API FDialogClipSettings();
};

FORCEINLINE uint32 GetTypeHash(const FDialogClipSettings) { return 0; }
