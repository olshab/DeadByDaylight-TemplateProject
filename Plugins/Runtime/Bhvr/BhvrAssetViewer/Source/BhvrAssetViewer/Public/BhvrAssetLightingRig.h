#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BhvrAssetLightingRig.generated.h"

class UBhvrAssetLightGroup;
class ULightComponent;

UCLASS()
class BHVRASSETVIEWER_API ABhvrAssetLightingRig : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient)
	UBhvrAssetLightGroup* KeyLightGroup;

	UPROPERTY(BlueprintReadOnly, Transient)
	UBhvrAssetLightGroup* FillLightGroup;

	UPROPERTY(BlueprintReadOnly, Transient)
	UBhvrAssetLightGroup* RimLightGroup;

	UPROPERTY(BlueprintReadOnly, Transient)
	UBhvrAssetLightGroup* KickLightGroup;

	UPROPERTY(BlueprintReadOnly, Transient)
	UBhvrAssetLightGroup* FogLightGroup;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FString GetDisplayName();

protected:
	UFUNCTION(BlueprintCallable)
	void AddRimLight(ULightComponent* InLight);

	UFUNCTION(BlueprintCallable)
	void AddKickLight(ULightComponent* InLight);

	UFUNCTION(BlueprintCallable)
	void AddKeyLight(ULightComponent* InLight);

	UFUNCTION(BlueprintCallable)
	void AddFogLight(ULightComponent* InLight);

	UFUNCTION(BlueprintCallable)
	void AddFillLight(ULightComponent* InLight);

public:
	ABhvrAssetLightingRig();
};

FORCEINLINE uint32 GetTypeHash(const ABhvrAssetLightingRig) { return 0; }
