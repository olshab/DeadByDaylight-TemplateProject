#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BhvrAssetEnvironmentSystem.generated.h"

class ABhvrAssetEnvironment;

UCLASS()
class BHVRASSETVIEWER_API ABhvrAssetEnvironmentSystem : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSelectedEnvironmentChanged);

public:
	UPROPERTY(BlueprintAssignable)
	FSelectedEnvironmentChanged SelectedEnvironmentChanged;

	UPROPERTY(BlueprintReadOnly, Transient)
	TArray<ABhvrAssetEnvironment*> Environments;

	UPROPERTY(BlueprintReadOnly, Transient)
	ABhvrAssetEnvironment* SelectedEnvironment;

public:
	UFUNCTION(BlueprintCallable)
	void SelectEnvironment(const FString& InDisplayName);

public:
	ABhvrAssetEnvironmentSystem();
};

FORCEINLINE uint32 GetTypeHash(const ABhvrAssetEnvironmentSystem) { return 0; }
