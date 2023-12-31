#pragma once

#include "CoreMinimal.h"
#include "Highlightable.h"
#include "MobileBaseUserWidget.h"
#include "UMGLevelBannerWidget.generated.h"

class UButton;
class UProgressBar;
class UHorizontalBox;
class UTextBlock;
class UAkAudioEvent;
class UImage;

UCLASS(Abstract, EditInlineNew)
class UUMGLevelBannerWidget : public UMobileBaseUserWidget, public IHighlightable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export)
	UButton* TooltipButton;

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* PlayerLevelText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* PlayerDevotionText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* PlayerCurrentExperienceText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* PlayerNextLevelExperienceText;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UProgressBar* XPProgressBar;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UHorizontalBox* XPTextContainer;

	UPROPERTY(EditDefaultsOnly)
	UAkAudioEvent* OnLongPressSound;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UImage* TooltipHighlightPicture;

public:
	UFUNCTION(BlueprintCallable)
	void StopHighlight();

	UFUNCTION(BlueprintCallable)
	void StartHighlight();

	UFUNCTION(BlueprintCallable)
	void SetProgressBarValue(const float progress);

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetInfoBP(const int32 playerLevel, const int32 playerPrestige, const int32 currentExperience, const int32 nextLevelExperience);

public:
	UFUNCTION(BlueprintCallable)
	void SetInfo(const int32 playerLevel, const int32 playerPrestige, const int32 currentExperience, const int32 nextLevelExperience);

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetExperienceVisibilityBP(const bool isExperienceVisible, const bool isBig);

	UFUNCTION()
	void OnTooltipButtonLongPressEvent();

public:
	UUMGLevelBannerWidget();
};

FORCEINLINE uint32 GetTypeHash(const UUMGLevelBannerWidget) { return 0; }
