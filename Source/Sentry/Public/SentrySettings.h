#pragma once

#include "CoreMinimal.h"
#include "EnableBuildTargets.h"
#include "AutomaticBreadcrumbs.h"
#include "UObject/NoExportTypes.h"
#include "EnableBuildConfigurations.h"
#include "TagsPromotion.h"
#include "SentrySettings.generated.h"

UCLASS(BlueprintType)
class SENTRY_API USentrySettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DsnUrl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Environment;

	UPROPERTY(EditAnywhere)
	bool InitAutomatically;

	UPROPERTY(EditAnywhere)
	bool EnableVerboseLogging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEnableBuildConfigurations EnableBuildConfigurations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEnableBuildTargets EnableBuildTargets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAutomaticBreadcrumbs AutomaticBreadcrumbs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTagsPromotion TagsPromotion;

	UPROPERTY(EditAnywhere)
	bool EnableAutoCrashCapturing;

	UPROPERTY(EditAnywhere)
	bool EnableAutoLogAttachment;

	UPROPERTY(EditAnywhere)
	bool EnableStackTrace;

	UPROPERTY(EditAnywhere)
	bool EnableAutoSessionTracking;

	UPROPERTY(EditAnywhere)
	int32 SessionTimeout;

	UPROPERTY(EditAnywhere)
	bool OverrideReleaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Release;

	UPROPERTY(EditAnywhere)
	bool UploadSymbolsAutomatically;

	UPROPERTY(EditAnywhere)
	FString ProjectName;

	UPROPERTY(EditAnywhere)
	FString OrgName;

	UPROPERTY(EditAnywhere)
	FString AuthToken;

	UPROPERTY(EditAnywhere)
	bool IncludeSources;

	UPROPERTY(EditAnywhere)
	FString CrashReporterUrl;

public:
	USentrySettings();
};

FORCEINLINE uint32 GetTypeHash(const USentrySettings) { return 0; }
