#pragma once

#include "CoreMinimal.h"
#include "EContext.h"
#include "UObject/SoftObjectPtr.h"
#include "Presenter.h"
#include "AnimationPreviewRequest.h"
#include "InputCoreTypes.h"
#include "AnimationPreviewPresenter.generated.h"

class UUserWidget;
class UAnimationPreviewSubsystem;

UCLASS(EditInlineNew)
class DBDUIPRESENTERS_API UAnimationPreviewPresenter : public UPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UUserWidget> AnimationPreviewWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EContext ObservedContext;

private:
	UFUNCTION()
	void OnKeyPressed(FKey key) const;

	UFUNCTION()
	void OnContextLeave(EContext context);

	UFUNCTION()
	void OnContextEnter(EContext context);

	UFUNCTION()
	void OnAnimationPreviewRequested(UAnimationPreviewSubsystem* animationPreviewSubsystem, FAnimationPreviewRequest& request);

	UFUNCTION()
	void OnAnimationPreviewCompleted(UAnimationPreviewSubsystem* animationPreviewSubsystem, const FAnimationPreviewRequest& request, bool completedSuccessfully) const;

	UFUNCTION()
	bool IsContextEntered() const;

public:
	UAnimationPreviewPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UAnimationPreviewPresenter) { return 0; }
