#include "RPCCountAnalytics.h"

FRPCCountAnalytics::FRPCCountAnalytics()
{
	this->MatchDuration = 0.0f;
	this->GameState = TEXT("");
	this->AllNamedCounts = TArray<FNamedRPCCount>();
	this->TotalCount = 0;
	this->UnlistedNames = TArray<FString>();
	this->UnlistedCount = 0;
	this->CallConsoleCmdOnServer_Server_Count = 0;
	this->ServerAcknowledgePossession_Count = 0;
	this->ServerCheckClientPossession_Count = 0;
	this->ServerCheckClientPossessionReliable_Count = 0;
	this->ServerMovePacked_Count = 0;
	this->ServerMoveOut_Count = 0;
	this->ServerNotifyLoadedWorld_Count = 0;
	this->ServerSetSpectatorLocation_Count = 0;
	this->ServerShortTimeout_Count = 0;
	this->ServerUpdateCamera_Count = 0;
	this->ServerUpdateLevelVisibility_Count = 0;
	this->ServerUpdateMultipleLevelsVisibility_Count = 0;
	this->ServerVerifyViewTarget_Count = 0;
	this->Server_ActivatePerk_Count = 0;
	this->Server_ActivateSkillCheck_Count = 0;
	this->Server_AddMaxSpeedMovementCurve_Count = 0;
	this->Server_Broadcast_ConfirmChargedCompleted_Count = 0;
	this->Server_Broadcast_StoreInteraction_Count = 0;
	this->Server_ClearTargets_Count = 0;
	this->Server_ClientPassedFence_Count = 0;
	this->Server_DeactivateSkillCheck_Count = 0;
	this->Server_EACMessageFromClient_Count = 0;
	this->Server_HitTarget_Count = 0;
	this->Server_SetImmobilized_Count = 0;
	this->Server_Launch_Count = 0;
	this->Server_LoadoutSpawned_Count = 0;
	this->Server_NotifyStunHasBeenProcessed_Count = 0;
	this->Server_OnIntroCompleted_Count = 0;
	this->Server_OnSkillCheckFailure_Count = 0;
	this->Server_OnSkillCheckSuccess_Count = 0;
	this->Server_SetOverlappingEscape_Count = 0;
	this->Server_PlayMontage_Count = 0;
	this->Server_PlayerReady_Count = 0;
	this->Server_ReceivePlayerProfile_Count = 0;
	this->Server_RemoveMaxSpeedMovementCurve_Count = 0;
	this->Server_RenderingFeaturesCompleted_Count = 0;
	this->Server_ReplicateControlRotation_Count = 0;
	this->Server_RequestEndGame_Count = 0;
	this->Server_RequestServerTime_Count = 0;
	this->Server_RequestStateChange_Count = 0;
	this->Server_SendAttackInput_Count = 0;
	this->Server_SendInteractionInput_Count = 0;
	this->Server_SendFastInteractionInput_Count = 0;
	this->Server_SendSecondaryActionPressed_Count = 0;
	this->Server_SetCharacterData_Count = 0;
	this->Server_SetConsecutiveMatchStreak_Count = 0;
	this->Server_SetCustomizationMeshes_Count = 0;
	this->Server_SetEquipedPerks_Count = 0;
	this->Server_SetEquipment_Count = 0;
	this->Server_SetInteractionToSwapTo_Count = 0;
	this->Server_SetIntroCompleted_Count = 0;
	this->Server_SetIsReadyToPlay_Count = 0;
	this->Server_SetMaxAcceleration_Count = 0;
	this->Server_SetPlayerGameState_Count = 0;
	this->Server_SetPlayerLoadout_Count = 0;
	this->Server_SetPlayerReady_Count = 0;
	this->Server_SetPlayerWiggleSkillCheckEnabled_Count = 0;
	this->Server_SetPreloadCompleted_Count = 0;
	this->Server_SetReadyToTravel_Count = 0;
	this->Server_SetSpectatorMode_Count = 0;
	this->Server_SendItemUseInput_Count = 0;
	this->Server_SendLeftRightMashedInput_Count = 0;
	this->Server_SetMaxSpeedMultiplierScalar_Count = 0;
	this->Server_SendMessage_Count = 0;
	this->Server_SetSettings_Count = 0;
	this->Server_SetRunInput_Count = 0;
	this->Server_SetStateStack_Count = 0;
	this->Server_SetStopSnapping_Count = 0;
	this->Server_StartSnapping_Count = 0;
	this->Server_StopMontage_Count = 0;
	this->Server_StoreAttack_Count = 0;
	this->Server_TryDetectPlayer_Count = 0;
	this->Server_UpdateDiscernedCharacters_Count = 0;
	this->Server_UpdateReplicatedPips_Count = 0;
	this->Server_UpdateScreenAspectRatio_Count = 0;
}
