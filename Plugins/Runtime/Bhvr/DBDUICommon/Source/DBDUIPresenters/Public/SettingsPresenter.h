#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Presenter.h"
#include "EOverlayTabs.h"
#include "SettingsPresenter.generated.h"

class UUserWidget;

UCLASS(EditInlineNew)
class DBDUIPRESENTERS_API USettingsPresenter : public UPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UUserWidget> SettingsWidgetClass;

protected:
	UFUNCTION()
	void OnTabEntered(const EOverlayTabs category);

private:
	UFUNCTION()
	bool IsUMGEnabled() const;

public:
	USettingsPresenter();
};

FORCEINLINE uint32 GetTypeHash(const USettingsPresenter) { return 0; }
