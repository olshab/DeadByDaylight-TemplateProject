#pragma once

#include "CoreMinimal.h"
#include "InjuredBleedoutKODelegate.generated.h"

class ADBDPlayer;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInjuredBleedoutKODelegate, ADBDPlayer*, injuredBleedoutInstigator);
