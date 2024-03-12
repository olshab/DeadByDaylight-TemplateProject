#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Pawn.h"
#include "BhvrAssetViewCamera.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BHVRASSETVIEWER_API ABhvrAssetViewCamera : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Export)
	UCameraComponent* Camera;

	UPROPERTY(BlueprintReadWrite)
	FVector PanFactorXY;

	UPROPERTY(BlueprintReadWrite)
	FVector RotationFactorXY;

	UPROPERTY(BlueprintReadWrite)
	float ZoomFactor;

private:
	UPROPERTY(EditAnywhere)
	float PanSpeed;

	UPROPERTY(EditAnywhere)
	float RotationSensitivity;

	UPROPERTY(EditAnywhere)
	float MinVerticalRotation;

	UPROPERTY(EditAnywhere)
	float MaxVerticalRotation;

	UPROPERTY(EditAnywhere)
	float ZoomSpeed;

	UPROPERTY(EditAnywhere)
	float DefaultZoomDistance;

	UPROPERTY(EditAnywhere)
	float MinZoomDistance;

	UPROPERTY(EditAnywhere)
	float MaxZoomDistance;

	UPROPERTY(EditAnywhere)
	float MinFocalDistance;

	UPROPERTY(EditAnywhere)
	float MaxFocalDistance;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float AspectRatio;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float ExposureBias;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float FieldOfView;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float RollAngle;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	bool bUseDepthOfField;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float BlurAmount;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	bool bUseAutoFocus;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	FVector AutoFocusOffsetXY;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	bool bShowAutoFocusTarget;

public:
	UFUNCTION(BlueprintCallable)
	void SetUseDepthOfField(bool bNewValue);

	UFUNCTION(BlueprintCallable)
	void SetUseAutoFocus(bool bNewValue);

	UFUNCTION(BlueprintCallable)
	void SetShowAutoFocusTarget(bool bNewValue);

	UFUNCTION(BlueprintCallable)
	void SetRollAngle(float NewRollAngle);

	UFUNCTION(BlueprintCallable)
	void SetFieldOfView(float NewFieldOfView);

	UFUNCTION(BlueprintCallable)
	void SetExposureBias(float NewExposureBias);

	UFUNCTION(BlueprintCallable)
	void SetBlurAmount(float NewBlurAmount);

	UFUNCTION(BlueprintCallable)
	void SetAutoFocusOffset(FVector NewFocusTargetOffsetXY);

	UFUNCTION(BlueprintCallable)
	void SetAspectRatio(float NewAspectRatio);

	UFUNCTION(BlueprintCallable)
	void PickPivotWithCursor();

	UFUNCTION(BlueprintCallable)
	void PickFocusWithCursor();

	UFUNCTION(BlueprintPure)
	float GetRollAngle() const;

	UFUNCTION(BlueprintPure)
	float GetFieldOfView() const;

	UFUNCTION(BlueprintPure)
	float GetExposureBias() const;

	UFUNCTION(BlueprintPure)
	float GetAspectRatio() const;

public:
	ABhvrAssetViewCamera();
};

FORCEINLINE uint32 GetTypeHash(const ABhvrAssetViewCamera) { return 0; }
