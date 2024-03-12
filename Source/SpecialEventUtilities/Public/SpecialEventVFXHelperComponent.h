#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "SpecialEventVFXHelperComponent.generated.h"

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class SPECIALEVENTUTILITIES_API USpecialEventVFXHelperComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLocallyObservedChangedDelegate);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHideVignetteTagAddedOrRemovedDelegate, bool, added);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHideVfxTagAddedOrRemovedDelegate, bool, added);

public:
	UPROPERTY(BlueprintAssignable)
	FHideVfxTagAddedOrRemovedDelegate OnHideVFXTagAddedOrRemoved;

	UPROPERTY(BlueprintAssignable)
	FHideVignetteTagAddedOrRemovedDelegate OnHideVignetteTagAddedOrRemoved;

	UPROPERTY(BlueprintAssignable)
	FLocallyObservedChangedDelegate OnLocallyObservedChanged;

private:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer _hideVFXTags;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer _killerOnlyHideVFXTags;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer _survivorOnlyHideVFXTags;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer _hideVignetteTags;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UActorComponent>> _componentsToSpawnOnHusk;

public:
	UFUNCTION(BlueprintCallable)
	void RegisterListeners();

public:
	USpecialEventVFXHelperComponent();
};

FORCEINLINE uint32 GetTypeHash(const USpecialEventVFXHelperComponent) { return 0; }
