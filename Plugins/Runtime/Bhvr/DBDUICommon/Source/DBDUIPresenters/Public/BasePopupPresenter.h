#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "EContext.h"
#include "Presenter.h"
#include "Templates/SubclassOf.h"
#include "BasePopupPresenter.generated.h"

class UUserWidget;
class UBasePopupViewData;

UCLASS(Abstract, EditInlineNew)
class DBDUIPRESENTERS_API UBasePopupPresenter : public UPresenter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EContext ObservedContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> PopupWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsWIP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UUserWidget> WIPPopupWidgetClass;

private:
	UPROPERTY(Transient)
	UBasePopupViewData* _viewData;

protected:
	UFUNCTION()
	void OnContextLeave(EContext context);

	UFUNCTION()
	void OnContextEnter(EContext context);

	UFUNCTION()
	bool IsContextEntered() const;

public:
	UBasePopupPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UBasePopupPresenter) { return 0; }
