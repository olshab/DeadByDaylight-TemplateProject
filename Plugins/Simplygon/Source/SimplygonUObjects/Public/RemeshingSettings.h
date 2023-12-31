#pragma once

#include "CoreMinimal.h"
#include "EHoleFilling.h"
#include "ERemeshingMode.h"
#include "ESurfaceTransferMode.h"
#include "RemeshingSettings.generated.h"

USTRUCT(BlueprintType)
struct FRemeshingSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 OnScreenSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EHoleFilling HoleFilling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERemeshingMode RemeshingMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESurfaceTransferMode SurfaceTransferMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HardEdgeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 TransferNormals : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 TransferColors : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 PopulateAttributeTessellationDisplacement : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GeometricalAccuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TopologicalAccuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RemeshingModeManualPositionX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RemeshingModeManualPositionY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RemeshingModeManualPositionZ;

	UPROPERTY()
	FString ProcessSelectionSetName;

	UPROPERTY()
	int32 ProcessSelectionSetID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 KeepUnprocessedSceneMeshes : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 ForceSoftEdgesWithinTextureCharts : 1;

public:
	SIMPLYGONUOBJECTS_API FRemeshingSettings();
};

FORCEINLINE uint32 GetTypeHash(const FRemeshingSettings) { return 0; }
