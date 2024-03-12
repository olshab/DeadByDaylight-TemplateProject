#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnimationPreviewProp.h"
#include "AnimationPreviewCharacter.h"
#include "AnimationPreviewRequest.h"
#include "AnimationPreview.generated.h"

UCLASS(Abstract)
class UAnimationPreview : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FAnimationPreviewCharacter> Characters;

	UPROPERTY()
	TArray<FAnimationPreviewProp> Props;

private:
	UPROPERTY()
	FAnimationPreviewRequest _request;

private:
	UFUNCTION()
	void OnRequiredClassesLoaded();

	UFUNCTION()
	void OnFadeOutForCompletionComplete(bool succeeded);

	UFUNCTION()
	void OnFadeInComplete();

	UFUNCTION()
	void OnAnimationStartFadeOutComplete();

public:
	UAnimationPreview();
};

FORCEINLINE uint32 GetTypeHash(const UAnimationPreview) { return 0; }
