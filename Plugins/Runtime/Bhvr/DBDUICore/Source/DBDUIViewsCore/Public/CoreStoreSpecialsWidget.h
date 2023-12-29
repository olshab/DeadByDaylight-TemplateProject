#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "StoreSpecialsViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "CoreStoreSpecialsWidget.generated.h"

class UCoreAuricCellsSpecialOfferWidget;
class UCorePreConstructableList;
class UCoreSelectableButtonWidget;
class UDBDWrapBox;

UCLASS(EditInlineNew)
class UCoreStoreSpecialsWidget : public UCoreBaseUserWidget, public IStoreSpecialsViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<UCoreSelectableButtonWidget> _itemWidgetClass;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UCoreAuricCellsSpecialOfferWidget* AuricCellSpecialOffer;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UDBDWrapBox* Container;

	UPROPERTY(EditAnywhere, NoClear)
	int32 _preConstructedItemsCount;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _itemList;

public:
	UCoreStoreSpecialsWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreSpecialsWidget) { return 0; }
