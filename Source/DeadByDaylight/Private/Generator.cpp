#include "Generator.h"
#include "OnAkPostEventCallback.h"
#include "PlayerFloatTuple.h"
#include "Net/UnrealNetwork.h"
#include "GeneratorDamageComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "DischargeUntilThresholdIsReachedComponent.h"

class UObject;
class ADBDPlayer;
class ACamperPlayer;
class UChargeableComponent;
class UAkAudioEvent;
class AActor;
class UInteractionDefinition;

void AGenerator::TriggerSkillCheckFailureLoudNoise(ADBDPlayer* instigatingPlayer)
{

}

void AGenerator::StopDischarge()
{

}

bool AGenerator::ShouldDoOverchargeSkillcheck() const
{
	return false;
}

void AGenerator::SetIsOvercharged(const bool overcharged)
{

}

void AGenerator::SetIsBlockedFromCharging(bool isBlockedFromCharging)
{

}

void AGenerator::SetIsAutoCompleted(const bool isAutoCompleted)
{

}

void AGenerator::SetFireLevelScoreEventOnFix(bool fireLevelScoreEventOnFixNew)
{

}

void AGenerator::ResetGenerator()
{

}

void AGenerator::RemovePlayerStartTime(const ADBDPlayer* player)
{

}

int32 AGenerator::PostAkEvent(UAkAudioEvent* AkEvent, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback)
{
	return 0;
}

void AGenerator::OnUpdateChargeProgress_Implementation(float newPercentComplete)
{

}

void AGenerator::OnRep_IsBlocked()
{

}

void AGenerator::OnRegressionStateChanged(const bool regressing, ADBDPlayer* lastDamageChangeSource)
{

}

void AGenerator::OnChargeChanged(UChargeableComponent* chargeableComponent, float percent)
{

}

void AGenerator::Multicast_PlayFailSparksFX_Implementation(ADBDPlayer* player, bool explode)
{

}

void AGenerator::Multicast_OnRepaired_Implementation(const bool showGeneratorCloneLoudNoise, const bool isAutoCompleted, const int32 updatedRemainingGeneratorCount)
{

}

bool AGenerator::IsRepaired() const
{
	return false;
}

bool AGenerator::IsBlocked() const
{
	return false;
}

bool AGenerator::IsBeingRepaired() const
{
	return false;
}

bool AGenerator::IsBeingDamagedByKiller() const
{
	return false;
}

TArray<ADBDPlayer*> AGenerator::GetRepairers() const
{
	return TArray<ADBDPlayer*>();
}

TArray<FPlayerFloatTuple> AGenerator::GetPlayerStartTimes() const
{
	return TArray<FPlayerFloatTuple>();
}

float AGenerator::GetPlayerStartTime(const ADBDPlayer* player) const
{
	return 0.0f;
}

bool AGenerator::GetIsBlockedFromCharging()
{
	return false;
}

bool AGenerator::GetIsAutoCompleted() const
{
	return false;
}

UGeneratorDamageComponent* AGenerator::GetGeneratorDamageComponent() const
{
	return NULL;
}

UChargeableComponent* AGenerator::GetGeneratorChargeComponent_Implementation() const
{
	return NULL;
}

void AGenerator::DisableInaccessibleInteractors()
{

}

bool AGenerator::CanSurvivorReactToBlockingEntity(const ACamperPlayer* survivor) const
{
	return false;
}

void AGenerator::BroadcastIsDamagedChangedEvent(ADBDPlayer* player)
{

}

void AGenerator::BroadcastGeneratorRepairedBySurvivor(ADBDPlayer* repairingSurvivor) const
{

}

void AGenerator::Authority_SetRepaired(const bool showGeneratorCloneLoudNoise, const bool isAutoCompleted)
{

}

void AGenerator::Authority_RepairDamage(ADBDPlayer* repairedBy)
{

}

void AGenerator::Authority_RemoveBlockingSource(const UObject* source)
{

}

void AGenerator::Authority_OnChargeChanged(UChargeableComponent* chargeableComponent, float percentCompletionChange, float totalPercentComplete)
{

}

void AGenerator::Authority_OnChargeApplied(float individualChargeAmount, float totalChargeAmount, AActor* chargeInstigator, bool wasCoop, float deltaTime)
{

}

void AGenerator::Authority_CancelRepairInteractions(const TArray<ADBDPlayer*>& repairers) const
{

}

void AGenerator::Authority_AddTimedBlockingSource(const UObject* source, const float blockingTime)
{

}

void AGenerator::Authority_AddBlockingSource(const UObject* source)
{

}

void AGenerator::AddPlayerStartTime(ADBDPlayer* player, float startTime)
{

}

void AGenerator::AddDamagingInteraction(UInteractionDefinition* interaction)
{

}

void AGenerator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGenerator, _isBlocked);
	DOREPLIFETIME(AGenerator, _isOvercharged);
}

AGenerator::AGenerator()
{
	this->Activated = false;
	this->WasASMCachePreWarmTriggered = false;
	this->IsPlaySkillcheckAesthetic = true;
	this->KillerOutlineFadeCurve = NULL;
	this->NativePercentComplete = 0.000000;
	this->_generatorDamageComponent = CreateDefaultSubobject<UGeneratorDamageComponent>(TEXT("GeneratorDamageComponent"));
	this->FireLevelScoreEventOnFix = false;
	this->_activatedTopLightsTransformMap = TMap<FName, FTransform>();
	this->_perceptionStimuliComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIPerceptionStimuliSourceComponent"));
	this->_regressChargeUntilThresholdIsReached = CreateDefaultSubobject<UDischargeUntilThresholdIsReachedComponent>(TEXT("RegressChargeUntilThresholdIsReached"));
	this->_isBlocked = false;
	this->_isBlockedFromCharging = false;
	this->_blockingSources = TSet<UObject*>();
	this->_generatorCharge = NULL;
	this->_playerStartTimes = TArray<FPlayerFloatTuple>();
	this->_isAutoCompleted = false;
	this->_isOvercharged = false;
	this->_coopRepairTracker = NULL;
	this->_VFX_LightDistanceDefault = 350.000000;
	this->_damagingInteractions = TArray<UInteractionDefinition*>();
	this->_authority_cachedInteractingPlayersOnCompletion = TArray<ADBDPlayer*>();
}
