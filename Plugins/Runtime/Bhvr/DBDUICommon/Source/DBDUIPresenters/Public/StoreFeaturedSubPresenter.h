#pragma once

#include "CoreMinimal.h"
#include "StoreSubPresenter.h"
#include "UObject/ScriptInterface.h"
#include "StoreFeaturedSubPresenter.generated.h"

class IStoreFeaturedViewInterface;

UCLASS()
class DBDUIPRESENTERS_API UStoreFeaturedSubPresenter : public UStoreSubPresenter
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TScriptInterface<IStoreFeaturedViewInterface> _storeFeaturedWidget;

public:
	UFUNCTION()
	void OnBackendStoreDataReceived(bool success);

public:
	UStoreFeaturedSubPresenter();
};

FORCEINLINE uint32 GetTypeHash(const UStoreFeaturedSubPresenter) { return 0; }
