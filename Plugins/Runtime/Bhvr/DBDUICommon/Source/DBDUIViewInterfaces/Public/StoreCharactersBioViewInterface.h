#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CharacterBioViewData.h"
#include "StoreCharactersBioViewInterface.generated.h"

UINTERFACE(Blueprintable)
class DBDUIVIEWINTERFACES_API UStoreCharactersBioViewInterface : public UInterface
{
	GENERATED_BODY()
};

class DBDUIVIEWINTERFACES_API IStoreCharactersBioViewInterface : public IInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetData(const FCharacterBioViewData& characterBioViewData);

};
