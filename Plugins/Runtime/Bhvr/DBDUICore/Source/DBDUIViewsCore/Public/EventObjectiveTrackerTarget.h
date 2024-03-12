#pragma once

#include "CoreMinimal.h"
#include "CoreBaseUserWidget.h"
#include "EventObjectiveTargetData.h"
#include "EventObjectiveTrackerTarget.generated.h"

UCLASS(EditInlineNew)
class UEventObjectiveTrackerTarget : public UCoreBaseUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetRewardPreviewVisible(const bool isVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void SetIsReached(const bool isReached);

	UFUNCTION(BlueprintImplementableEvent)
	void SetData(const FEventObjectiveTargetData& data);

public:
	UEventObjectiveTrackerTarget();
};

FORCEINLINE uint32 GetTypeHash(const UEventObjectiveTrackerTarget) { return 0; }
