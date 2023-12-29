#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoreItemViewData.h"
#include "StoreSpecialsItemViewData.generated.h"

UCLASS()
class DBDUIVIEWINTERFACES_API UStoreSpecialsItemViewData : public UStoreItemViewData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient)
	FDateTime EndTime;

	UPROPERTY(BlueprintReadOnly, Transient)
	UStoreItemViewData* Item;

public:
	UStoreSpecialsItemViewData();
};

FORCEINLINE uint32 GetTypeHash(const UStoreSpecialsItemViewData) { return 0; }
