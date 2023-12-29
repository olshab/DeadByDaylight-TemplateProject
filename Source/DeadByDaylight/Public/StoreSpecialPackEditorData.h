#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DBDTableRowBase.h"
#include "StoreSpecialPackItem.h"
#include "StoreSpecialPackEditorData.generated.h"

USTRUCT(BlueprintType)
struct FStoreSpecialPackEditorData: public FDBDTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FSoftObjectPath Image;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString InclusionVersion;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Discount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SortOrder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString DLCId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FStoreSpecialPackItem> Content;

public:
	DEADBYDAYLIGHT_API FStoreSpecialPackEditorData();
};

FORCEINLINE uint32 GetTypeHash(const FStoreSpecialPackEditorData) { return 0; }
