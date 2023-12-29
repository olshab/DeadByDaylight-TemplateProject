#pragma once

#include "CoreMinimal.h"
#include "CoreButtonWidget.h"
#include "EItemFilterOption.h"
#include "CoreFilterButtonWidget.generated.h"

class UDBDImage;
class UTexture2D;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCoreFilterButtonWidget : public UCoreButtonWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDImage* LabelIMG;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	EItemFilterOption _filterOption;

	UPROPERTY(BlueprintReadOnly)
	bool _isToggled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* FavoriteTagTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* OwnedTagTexture;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	bool _defaultToggleState;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UpdateVisualState();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetupTextOnly(const FText& label);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetupImageOnly(UTexture2D* texture);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetupImageAndText(UTexture2D* texture, const FText& label);

	UFUNCTION(BlueprintCallable)
	void SetToggledState(bool isToggled);

	UFUNCTION(BlueprintPure)
	bool IsToggled() const;

public:
	UCoreFilterButtonWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreFilterButtonWidget) { return 0; }
