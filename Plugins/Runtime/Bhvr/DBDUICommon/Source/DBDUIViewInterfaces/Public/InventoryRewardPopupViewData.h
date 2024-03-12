#pragma once

#include "CoreMinimal.h"
#include "GrantedRewardPopupViewData.h"
#include "InventoryRewardPopupViewData.generated.h"

UCLASS()
class DBDUIVIEWINTERFACES_API UInventoryRewardPopupViewData : public UGrantedRewardPopupViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FName Id;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	int32 Amount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	bool HasGameSpecificData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient)
	FString GameSpecificData;

public:
	UInventoryRewardPopupViewData();
};

FORCEINLINE uint32 GetTypeHash(const UInventoryRewardPopupViewData) { return 0; }
