#pragma once

#include "CoreMinimal.h"
#include "Perk.h"
#include "K35P03.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UK35P03 : public UPerk
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	int32 _maxTokens;

	UPROPERTY(EditDefaultsOnly)
	int32 _tokenGain;

	UPROPERTY(EditDefaultsOnly)
	float _cooldownTime;

public:
	UK35P03();
};

FORCEINLINE uint32 GetTypeHash(const UK35P03) { return 0; }
