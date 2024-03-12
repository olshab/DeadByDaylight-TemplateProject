#pragma once

#include "CoreMinimal.h"
#include "GenericPopupViewData.h"
#include "RewardPopupViewData.generated.h"

class UGrantedRewardPopupViewData;

UCLASS()
class DBDUIVIEWINTERFACES_API URewardPopupViewData : public UGenericPopupViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FName BundleId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	TArray<UGrantedRewardPopupViewData*> Rewards;

public:
	URewardPopupViewData();
};

FORCEINLINE uint32 GetTypeHash(const URewardPopupViewData) { return 0; }
