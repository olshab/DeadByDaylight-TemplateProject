#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "PlayerProfileViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "PlayerProfileClickedDelegate.h"
#include "PlayerCardViewData.h"
#include "CorePlayerProfileWidget.generated.h"

class UCorePlayerNameWidget;
class UTexture2D;
class UCoreButtonWidget;
class UCoreWalletWidget;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCorePlayerProfileWidget : public UCoreBaseUserWidget, public IPlayerProfileViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UCoreButtonWidget* PlayerCardButton;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UCoreWalletWidget* Wallet;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UCorePlayerNameWidget* PlayerName;

	UPROPERTY()
	FPlayerProfileClickedDelegate _onPlayerProfileClickedDelegate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float _playerCardEnabledOpacity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float _playerCardDisabledOpacity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float _playerProfileFocusOpacity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float _playerProfileUnfocusOpacity;

	UPROPERTY(BlueprintReadOnly)
	bool _isProfileMenuContextEntered;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetBadgeBannerData(const TSoftObjectPtr<UTexture2D>& badge, const FPlayerCardViewData& banner, const bool showBanner);

private:
	UFUNCTION(BlueprintCallable)
	void OnPlayerProfileClicked(UCoreButtonWidget* button);

	UFUNCTION()
	void OnPlayerCardButtonUnhovered(UCoreButtonWidget* button);

	UFUNCTION()
	void OnPlayerCardButtonHovered(UCoreButtonWidget* button);

public:
	UFUNCTION()
	virtual void SetPlayerCardEnabled(bool isEnabled) override PURE_VIRTUAL(SetPlayerCardEnabled,);

public:
	UCorePlayerProfileWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCorePlayerProfileWidget) { return 0; }
