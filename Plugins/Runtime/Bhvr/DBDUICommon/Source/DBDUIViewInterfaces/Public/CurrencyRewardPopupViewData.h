#pragma once

#include "CoreMinimal.h"
#include "GrantedRewardPopupViewData.h"
#include "ECurrencyType.h"
#include "AuricCellsBundleViewData.h"
#include "CurrencyRewardPopupViewData.generated.h"

UCLASS()
class DBDUIVIEWINTERFACES_API UCurrencyRewardPopupViewData : public UGrantedRewardPopupViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	ECurrencyType Currency;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	int32 Amount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool HasSourcePackId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FString SourcePackId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FAuricCellsBundleViewData AuricCellsBundleViewData;

public:
	UCurrencyRewardPopupViewData();
};

FORCEINLINE uint32 GetTypeHash(const UCurrencyRewardPopupViewData) { return 0; }
